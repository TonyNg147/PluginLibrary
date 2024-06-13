#include "MainWindow.h"
#include <QDebug>
void MainWindow::init(QCoreApplication* app)
{
    if (app)
    {
        m_applicationPointer = app;
        m_applicationDirPath = app->applicationDirPath();
    }
}

void MainWindow::addResourcePath(const QString& path)
{

}

void MainWindow::setWindowEntry(const QString& path)
{
    m_entryPath = path;
}

void MainWindow::exec(bool usedDefaultPath)
{
    Q_ASSERT_X(m_applicationPointer != nullptr, "Execute", "Must init the MainWindow with the QCoreApplication");

    QString entry;

    constexpr const char* cDefaultPath = "qrc:/View/MainView.qml";

    if (usedDefaultPath)
    {
        entry = cDefaultPath;
    }
    else
    {
        Q_ASSERT_X(m_entryPath,"Execute", "Must setWindowEntry if custom windowEntry is needed");

        entry = m_entryPath.value();
    }
    qDebug() << "Path is " << entry;
    m_window.setSource(entry);
    m_window.show();
}
