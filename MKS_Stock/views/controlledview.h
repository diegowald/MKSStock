#ifndef CONTROLLEDVIEW_H
#define CONTROLLEDVIEW_H

#include <QMainWindow>

class ControllerBase;

class ControlledView : public QMainWindow
{
    Q_OBJECT
public:
    explicit ControlledView(QWidget *parent = 0);
    void setController(ControllerBase *controller);

    virtual void refresh() = 0;
    QStringList headers();

protected:
    ControllerBase *controller();
signals:

public slots:

private:
    ControllerBase *_controller;
};

#endif // CONTROLLEDVIEW_H
