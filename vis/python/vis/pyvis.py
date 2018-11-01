import numpy as np

#
# courtesy root_numpy, remove support for TH1C
#

DTYPE_ROOT2NUMPY = dict(C='i1', S='i2', I='i4', L='i8', F='f4', D='f8')

def hist2array(hist, include_overflow=False, copy=True, return_edges=False):
    """Convert a ROOT histogram into a NumPy array

    Parameters
    ----------
    hist : ROOT TH1, TH2, TH3, THn, or THnSparse
        The ROOT histogram to convert into an array
    include_overflow : bool, optional (default=False)
        If True, the over- and underflow bins will be included in the
        output numpy array. These bins are excluded by default.
    copy : bool, optional (default=True)
        If True (the default) then copy the underlying array, otherwise the
        NumPy array will view (and not own) the same memory as the ROOT
        histogram's array.
    return_edges : bool, optional (default=False)
        If True, also return the bin edges along each axis.

    Returns
    -------
    array : numpy array
        A NumPy array containing the histogram bin values
    edges : list of numpy arrays
        A list of numpy arrays where each array contains the bin edges along
        the corresponding axis of ``hist``. Overflow and underflow bins are not
        included.

    Raises
    ------
    TypeError
        If hist is not a ROOT histogram.

    See Also
    --------
    array2hist

    """
    import ROOT
    # Determine dimensionality and shape
    simple_hist = True
    if isinstance(hist, ROOT.TH3):
        shape = (hist.GetNbinsZ() + 2,
                 hist.GetNbinsY() + 2,
                 hist.GetNbinsX() + 2)
    elif isinstance(hist, ROOT.TH2):
        shape = (hist.GetNbinsY() + 2, hist.GetNbinsX() + 2)
    elif isinstance(hist, ROOT.TH1):
        shape = (hist.GetNbinsX() + 2,)
    elif isinstance(hist, ROOT.THnBase):
        shape = tuple([hist.GetAxis(i).GetNbins() + 2
                       for i in range(hist.GetNdimensions())])
        simple_hist = False
    else:
        raise TypeError(
            "hist must be an instance of ROOT.TH1, "
            "ROOT.TH2, ROOT.TH3, or ROOT.THnBase")

    # Determine the corresponding numpy dtype
    if simple_hist:
        for hist_type in 'DFISC':
            if isinstance(hist, getattr(ROOT, 'TArray{0}'.format(hist_type))):
                break
        else:
            raise AssertionError(
                "hist is somehow an instance of TH[1|2|3] "
                "but not TArray[D|F|I|S|C]")
    else:  # THn, THnSparse
        if isinstance(hist, ROOT.THnSparse):
            cls_string = 'THnSparse{0}'
        else:
            cls_string = 'THn{0}'
        for hist_type in 'CSILFD':
            if isinstance(hist, getattr(ROOT, cls_string.format(hist_type))):
                break
        else:
            raise AssertionError(
                "unsupported THn or THnSparse bin type")

    if simple_hist:
        # Constuct a NumPy array viewing the underlying histogram array

        # if hist_type == 'C':
        #     array_func = getattr(_librootnumpy,
        #                          'array_h{0}c'.format(len(shape)))
        #     array = array_func(ROOT.AsCObject(hist))
        #     array.shape = shape
        # else:
        
        dtype = np.dtype(DTYPE_ROOT2NUMPY[hist_type])
        array = np.ndarray(shape=shape, dtype=dtype,
                               buffer=hist.GetArray())
    else:  # THn THnSparse
        dtype = np.dtype(DTYPE_ROOT2NUMPY[hist_type])
        if isinstance(hist, ROOT.THnSparse):
            array = _librootnumpy.thnsparse2array(ROOT.AsCObject(hist),
                                                  shape, dtype)
        else:
            array = _librootnumpy.thn2array(ROOT.AsCObject(hist),
                                            shape, dtype)

    if return_edges:
        if simple_hist:
            ndims = hist.GetDimension()
            axis_getters = ['GetXaxis', 'GetYaxis', 'GetZaxis'][:ndims]
        else:
            ndims = hist.GetNdimensions()
            axis_getters = ['GetAxis'] * ndims

        edges = []
        for idim, axis_getter in zip(range(ndims), axis_getters):
            # GetXaxis expects 0 parameters while we need the axis in GetAxis
            ax = getattr(hist, axis_getter)(*(() if simple_hist else (idim,)))
            # `edges` is Nbins + 1 in order to have the last bin's upper edge as well
            edges.append(np.empty(ax.GetNbins() + 1, dtype=np.double))
            # load the lower edges into `edges`
            ax.GetLowEdge(edges[-1])
            # Get the upper edge of the last bin
            edges[-1][-1] = ax.GetBinUpEdge(ax.GetNbins())

    if not include_overflow:
        # Remove overflow and underflow bins
        array = array[tuple([slice(1, -1) for idim in range(array.ndim)])]

    if simple_hist:
        # Preserve x, y, z -> axis 0, 1, 2 order
        array = np.transpose(array)
        if copy:
            array = np.copy(array)

    if return_edges:
        return array, edges
    return array
