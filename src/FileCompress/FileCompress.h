/*
 * FileCompress.h
 *
 *  Created on: 30. jul. 2015
 *      Author: Bojan
 */

#ifndef FILECOMPRESS_H_
#define FILECOMPRESS_H_

#include <QProcess>

class FileCompress: public QObject
{
    Q_OBJECT
public:
    FileCompress();
    virtual ~FileCompress();
    void compress(QStringList fileName, QString outputFile);
    void decompress(QString fileNames, QString outputFolder);
private:
    void startProcess(QString process, QStringList arguments);
    QProcess* zip;

    private slots:
    //void onError(QProcess::ProcessError error);
    void onFinished(int exitCode, QProcess::ExitStatus exitStatus);
    //void onStarted();
    //void onStateChanged(QProcess::ProcessState newState);
    signals:
    void error(QProcess::ProcessError error);
    void finished(int exitCode, QProcess::ExitStatus exitStatus);
    void started();
    void stateChanged(QProcess::ProcessState newState);
};

#endif /* FILECOMPRESS_H_ */
