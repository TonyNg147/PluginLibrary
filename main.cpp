#include <QObject>
#include <QLibrary>
#include <QGuiApplication>
#include <UIInterface.h>

int main(int argc, char** argv)
{
    QGuiApplication app(argc, argv);

    QLibrary lib;

    const QString libPath = app.applicationDirPath().append("/lib/UILib.dll");
    lib.setFileName(libPath);

    if (!lib.load())
    {
        qCritical()<<"Cannot load the library";
        std::abort();
    }

    qDebug() << "Load the library successfully";

    UIInstance UIImpl = reinterpret_cast<UIInstance>(lib.resolve("queryInterface"));

    if (UIImpl == nullptr)
    {
        qCritical()<<"Cannot resolve the symbol queryInterface " << lib.errorString();
        std::abort();
    }

    qDebug() << "Found the CUI Implmentation";

    CUI* ui = UIImpl();

    ui->init(&app);
    ui->exec();

    return app.exec();
}
