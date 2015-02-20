#ifndef __RENDERMOON_CORE_PARAMSET_ITEM__
#define __RENDERMOON_CORE_PARAMSET_ITEM__

template <typename T> struct ParamSetItem : public ReferenceCounted
{
    // ParamSetItem Public Methods
    ParamSetItem(const string &name, const T *val, int nItems = 1);
    ~ParamSetItem()
    {
        delete[] data;
    }

    // ParamSetItem Data
    string name;
    int nItems;
    T *data;
    mutable bool lookedUp;
};



// ParamSetItem Methods
template <typename T>
ParamSetItem<T>::ParamSetItem(const string &n, const T *v, int ni)
{
    name = n;
    nItems = ni;
    data = new T[nItems];
    for (int i = 0; i < nItems; ++i) data[i] = v[i];
    lookedUp = false;
}

#endif
