
#include <gtkmm.h>

class Window : public Gtk::Window {
public:
  Gtk::VBox vbox;
  Gtk::Entry fornavn;
  Gtk::Entry etternavn;
  Gtk::Button button;
  Gtk::Label label;
  Gtk::Label labelFirst;
  Gtk::Label labelLast;
  

  Window() {
    button.set_label("Click here");
    labelFirst.set_text("first name");
    labelLast.set_text("Last name");

    vbox.pack_start(labelFirst);
    vbox.pack_start(fornavn);  //Add the widget entry to vbox
    vbox.pack_start(labelLast);
    vbox.pack_start(etternavn);
    vbox.pack_start(button); //Add the widget button to vbox
    vbox.pack_start(label);  //Add the widget label to vbox

    add(vbox);  //Add vbox to window
    show_all(); //Show all widgets
    button.set_sensitive(false);
    

    fornavn.signal_changed().connect([this]() {
      button.set_sensitive(fornavn.get_text().length()> 0 && etternavn.get_text().length()>0);
    });
    
    etternavn.signal_changed().connect([this](){
      button.set_sensitive(fornavn.get_text().length()> 0 && etternavn.get_text().length()>0);
    });


    button.signal_clicked().connect([this]() {
      label.set_text("Combined: " + fornavn.get_text() + " " + etternavn.get_text());
    });
  }
};

int main() {
  Gtk::Main gtk_main;
  Window window;
  gtk_main.run(window);
}