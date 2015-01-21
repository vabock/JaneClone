#ifndef PATHCOMB_HPP_
#define PATHCOMB_HPP_

#include <wx/string.h>
#include <wx/filename.h>


template <typename T>
void wxPathCombine_impl(wxFileName& fn, const T& t)
{
     fn.SetFullName(t);
}

template <typename First, typename... Rest>
void wxPathCombine_impl(wxFileName& fn, const First& first, const Rest&... rest)
{
     fn.AppendDir(first);
     wxPathCombine_impl(fn, rest...);
}

template <typename First, typename... Rest>
wxString wxPathCombine(const First& first, const Rest&... rest)
{
     wxFileName fn = wxFileName::DirName(first);
     wxPathCombine_impl(fn, rest...);

     return fn.GetFullPath();
}

#if 0
#include <iostream>
int main()
{
     std::cout << wxPathCombine(wxT("/usr/hoge"), wxT("fuga"), wxT("piyo.png")) << std::endl;
     return 0;
}
#endif

#endif // PATHCOMB_HPP_
