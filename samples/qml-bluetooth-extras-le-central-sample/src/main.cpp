#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QLoggingCategory>

int main(int argc, char* argv[]){
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:///src/main.qml")));
    QLoggingCategory::setFilterRules(QStringLiteral("qt.bluetooth* = true"));
    return app.exec();
}
