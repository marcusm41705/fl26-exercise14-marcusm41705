// write_file.cpp
#include <QFile>
#include <QDataStream>
#include <QDebug>
#include <QList>
#include <QString>
#include <cstdlib>
#include "file_header.h"
  
int main(int argc, char *argv[])
{
  QFile file("temp.dat");
  QList<QString> msgs; //creating Qlist of QStrings

  file.open(QIODevice::WriteOnly);

  // treat the file as consuming a data stream
  QDataStream out(&file);

  // Write a header with a magic number and a version
  out << MAGIC;
  out << VERSION;

  // use a specific streaming format
  out.setVersion(QDataStream::Qt_5_0);
  
  // write some data
 msgs.append("This is a test.");
 msgs.append("This is only a test.");
 msgs.append("Another test message for QList using QDataStream.");
 out << msgs;
  
  // notify the user that we're finished
  qDebug() << "A data stream has been written to a file.";  
  
  return EXIT_SUCCESS;
}
