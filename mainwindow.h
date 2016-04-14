#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCheckBox>
#include <QButtonGroup>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void chkChanged(void);

private:
    Ui::MainWindow *ui;
    QButtonGroup *chk_group[2];
    QCheckBox *exclusive[3];
    QCheckBox *non_exclusive[3];
    int xpos=30;
    int ypos=30;
};

#endif // MAINWINDOW_H
