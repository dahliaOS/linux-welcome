#include <gtk/gtk.h>
#include <iostream>

int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *window;
 
    gtk_init(&argc, &argv);
 
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "dahlia-layout.glade", NULL);
 
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window1"));
    gtk_builder_connect_signals(builder, NULL);
  
    g_object_unref(builder);
 
    gtk_widget_show(window);                
    gtk_main();
 
    return 0;
}

void on_shutBT_clicked()
{
  std::cout << "static constructor\n";
}

void on_terminalBT_clicked()
{
    std::cout << "static constructor\n";
}

void on_desktop_clicked()
{
    std::cout << "static constructor\n";
}
// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}