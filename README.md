# File-Compress
Compressing and decompressing files using QProcess

# What example does
It uses QProcess to use QNXs zip commands. Zip and unzip both work.
- "Compress file" will zip together both `testfile.txt` and `testfile2.txt` located in `assets/`, and save it as `zipped.zip` inside `data/` folder
- Decompress will take `zipped.zip` and decompress it inside `data/`
If you try to unzip the file that does not exist, you will only see the error in console. There is no zip error reporting.

Zip options are different from Linux, so I suggest reading documentation if you would like to change them:  [ZIP](http://www.qnx.com/developers/docs/6.3.0SP3/neutrino/utilities/z/zip.html) - [UNZIP](http://www.qnx.com/developers/docs/6.3.0SP3/neutrino/utilities/u/unzip.html)

# How to add to your own project
Copy whole FileCompress folder to your src/

First add this to your .h file:
```
#include "FileCompress/FileCompress.h"
```

And this:
```
private:
    FileCompress* compressFile;
```
    
To compress, use
```
compressFile = new FileCompress();
compressFile->compress(files, outputFile);
 ```
 
To decompress, use
```
compressFile = new FileCompress();
compressFile->decompress(zipFile, outputFolder);
```

Signals:
```
void error(QProcess::ProcessError error);
void finished(int exitCode, QProcess::ExitStatus exitStatus);
void started();
void stateChanged(QProcess::ProcessState newState);
```
