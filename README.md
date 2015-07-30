# File-Compress
Compressing and decompressing files using QProcess

# How to use
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
