int main()
{

    std::vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::list<int> cpylist;
    std::vector<int>::reverse_iterator rit = ivec.rbegin();
    rit += 2;
    while (rit != ivec.rend() - 3)
    {
        cpylist.push_back(*rit);
        rit++;
    }
    cout << "cpylist: ";
    for (auto it : cpylist)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
