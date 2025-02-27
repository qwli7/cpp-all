int main()
{

    std::list<int> lst = {1, 2, 3, 4, 5, 0, 7, 8, 0, 10};
    //反向迭代器查找
    std::list<int>::reverse_iterator rit = std::find(lst.rbegin(), lst.rend(), 0);
    if (rit == lst.rend())
    {
        cout << "not found" << endl;
    }
    else
    {
        cout << "found: " << *rit << endl;
    }
    // cout << "reverse_iterator: " << *rit << endl;
    return 0;
}
