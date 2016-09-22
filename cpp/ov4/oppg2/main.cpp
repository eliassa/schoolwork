
#include <gtkmm.h>

class Window : public Gtk::Window {
public:
  Gtk::VBox vbox;
  Gtk::Entry fornavn;
  Gtk::Entry etternavn;
  Gtk::Button button;
  Gtk::Label label;

  Window() {
    button.set_label("Click here");

    vbox.pack_start(fornavn);  //Add the widget entry to vbox
    vbox.pack_start(etternavn);
    vbox.pack_start(button); //Add the widget button to vbox
    vbox.pack_start(label);  //Add the widget label to vbox

    add(vbox);  //Add vbox to window
    show_all(); //Show all widgets
    
    fornavn.set_text("fornavn");
    etternavn.set_text("etternavn");

    fornavn.signal_changed().connect([this]() {
      label.set_text("names combined: " + fornavn.get_text()+ " "+ etternavn.get_text());
    });
    
    etternavn.signal_changed().connect([this](){
      label.set_text("names combined: " + fornavn.get_text()+" " +etternavn.get_text());
    });

    fornavn.signal_activate().connect([this]() {
      label.set_text("Entry activated");
      fornavn.set_text("");
    });
    
    etternavn.signal_activate().connect([this]() {
      label.set_text("Entry activated");
    });

    button.signal_clicked().connect([this]() {
      label.set_text("Button clicked");
    });
  }
};

int main() {
  Gtk::Main gtk_main;
  Window window;
  gtk_main.run(window);
}