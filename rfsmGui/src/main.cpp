/*
 * Copyright (C) 2015 iCub Facility
 * Authors: Ali Paikan
 * CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT
 *
 */

#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QCoreApplication::setApplicationName("rFSM Gui");
    QCoreApplication::setApplicationVersion("1.0.0");

    QCommandLineParser parser;
    parser.setApplicationDescription("A graphical tool for run and debug rFSM state machines");
    parser.addHelpOption();
    parser.addVersionOption();
    //parser.addPositionalArgument("source", QCoreApplication::translate("main", "Source file to copy."));

    // An option with a value
    QCommandLineOption targetDirectoryOption(QStringList() << "f" << "rfsm",
            QCoreApplication::translate("main", "load <state-machine> at startup"),
            QCoreApplication::translate("main", "state-machine"));
    parser.addOption(targetDirectoryOption);

    // A boolean option with multiple names (-r, --run)
    QCommandLineOption forceOption(QStringList() << "r" << "run",
            QCoreApplication::translate("main", "run the state machine at startup"));
    parser.addOption(forceOption);

    // Process the actual command line arguments given by the user
    parser.process(app);

    MainWindow w(&parser);
    w.show();
    return app.exec();
}