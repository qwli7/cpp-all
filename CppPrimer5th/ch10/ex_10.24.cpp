bool check_size(const string &s, std::string::size_type sz)
{
    return s.size() < sz;
}

int main()
{

    std::string str = "hello";
    auto check = std::bind(check_size, str, std::placeholders::_1);
    std::vector<int> v = {3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int>::iterator it = std::find_if(v.begin(), v.end(), check);
    cout << "find_if founded " << *it << endl;

    for (auto i : v)
    {
        if (check(i))
        {
            cout << "forloop founded: " << i << endl;
            break;
        }
    }
    return 0;
}
