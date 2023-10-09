//
// Created by Daniel Byomujuni on 9/6/23.
//
#ifndef VAULT_FRAME_H
#define VAULT_FRAME_H
#include <wx/wx.h>
class Frame : public wxFrame
{
private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

public:
    Frame();
};

#endif //VAULT_FRAME_H
