/*
 * FileCompress.cpp
 *
 *  Created on: 30. jul. 2015
 *      Author: Bojan
 */

#include "FileCompress.h"

#include <QDebug>
#include <QDir>
#include <QFile>

FileCompress::FileCompress()
{
    zip = new QProcess(this);
}

FileCompress::~FileCompress()
{
    zip->deleteLater();
}

void FileCompress::startProcess(QString process, QStringList arguments)
{

    qDebug() << arguments;

    zip = new QProcess(this);

    zip->setReadChannel(QProcess::StandardOutput);
    zip->start(process, arguments);

    connect(zip, SIGNAL(error(QProcess::ProcessError)), this, SIGNAL(error(QProcess::ProcessError)));
    connect(zip, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(onFinished(int, QProcess::ExitStatus)));
    connect(zip, SIGNAL(started()), this, SIGNAL(started()));
    connect(zip, SIGNAL(stateChanged(QProcess::ProcessState)), this, SIGNAL(stateChanged(QProcess::ProcessState)));

}

void FileCompress::compress(QStringList fileNames, QString outputFile)
{
    QStringList arguments;
    // to not include only files
    arguments << "-j";
    arguments << outputFile;
    arguments << fileNames;

    startProcess("zip", arguments);
}

void FileCompress::decompress(QString fileName, QString outputFile)
{
    QStringList arguments;
    arguments << fileName;

    arguments << "-d" << outputFile;

    startProcess("unzip", arguments);
}

void FileCompress::onFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    qDebug() << "[FileCompress.onFinished]: Output" << zip->readAllStandardOutput();
    emit finished(exitCode, exitStatus);
}
