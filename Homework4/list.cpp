void listAll(const Domain* d, string path) // two-parameter overload
{
    if (d->subdomains().empty())
        cout << path << endl;

    for (int i = 0; i < d->subdomains().size(); i++)
    {
        if (path == "")
            listAll(d->subdomains().at(i), d->subdomains().at(i)->label() + path);
        else
            listAll(d->subdomains().at(i),  d->subdomains().at(i)->label() + "." + path);
    }
}
