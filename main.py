import gi
bashCommand = "cwm --rdf test.rdf --ntriples > test.nt"
import subprocess

gi.require_version("Gtk", "3.0")
from gi.repository import Gtk


class Handler:
    def onDestroy(self, *args):
        Gtk.main_quit()

    def onButtonPressed(self, terminalBT):
        print("Hello World!")
        subprocess.run('xterm',
        shell=True,
        # Probably don't forget these, too
        check=True, text=True)

builder = Gtk.Builder()
builder.add_from_file("dahlia-layout.glade")
builder.connect_signals(Handler())

window = builder.get_object("window1")
window.show_all()

Gtk.main()