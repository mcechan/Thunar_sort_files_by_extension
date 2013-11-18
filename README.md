Thunar sorts files by their MIME types (so does Nautilus) but often it miscategorizes a file's MIME type and it always treats all plain text files as a single type. This puts lots of pain on users who prefer to having their file manager sorting files by extension. Quite some bug reports have been filed to the official Bugzilla but people in power do not think it is a bug, rather, a good feature. I myself have been bugged by this bug for quite a while -- I often have to process thousands of text files of different types AKA extensions and not being able to separate them in my file manager is a real torture, so I did a little bit tweaking of the Thunar source code... and here you go, just download the whole thing, and compile your own Thunar (cd to the Thunar directory and run "./configure; make; make install"). Happy Thunaring!
