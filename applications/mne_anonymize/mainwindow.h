#ifndef MNEANONYMIZE_MAINWINDOW_H
#define MNEANONYMIZE_MAINWINDOW_H

#include <QMainWindow>
#include <QDateTime>

namespace Ui {
class MainWindow;
}

namespace MNEANONYMIZE {
class SettingsControllerGui;
}

namespace MNEANONYMIZE {

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(SettingsControllerGui* controller = nullptr);

    ~MainWindow() override;

    void setLineEditInFile(const QString& s);
    void setLineEditOutFile(const QString &s);

    void setCheckBoxBruteMode(bool b);

    void setMeasurementDate(const QDateTime& dt);
    void setCheckBoxMeasurementDateOffset(bool o);
    void setMeasurementDateOffset(int d);

    void setSubjectBirthday(const QDateTime& d);
    void setCheckBoxSubjectBirthdayOffset(bool b);
    void setSubjectBirthdayOffset(int d);

    void setSubjectHis(const QString& h);

public slots:
    void setLineEditIdFileVersion(double v);
    void setLineEditIdMeasurementDate(QDateTime d);
    void setLineEditIdMacAddress(QString mac);
    void setLineEditFileMeasurementDate(QDateTime d);
    void setLineEditFileComment(QString c);
    void setLineEditFileExperimenter(QString e);

    void setLineEditSubjectId(int i);
    void setLineEditSubjectFirstName(QString fn);
    void setLineEditSubjectMiddleName(QString mn);
    void setLineEditSubjectLastName(QString ln);
    void setLineEditSubjectBirthday(QDateTime b);
    void setLineEditSubjectSex(int s);
    void setLineEditSubjectHand(int h);
    void setLineEditSubjectWeight(float w);
    void setLineEditSubjectHeight(float h);
    void setLineEditSubjectComment(QString c);
    void setLineEditSubjectHisId(QString his);

    void setLineEditProjectId(int);
    void setLineEditProjectName(QString);
    void setLineEditProjectAim(QString);
    void setLineEditProjectPersons(QString);
    void setLineEditProjectComment(QString);

    void setLabelMriDataFoundVisible(bool);

protected:
    void closeEvent(QCloseEvent *event) override;

signals:
    void fileInChanged(const QString& s) const;
    void fileOutChanged(const QString& s) const;
    void bruteModeChanged(bool b) const;
    void measurementDateChanged(const QDateTime& t) const;
    void useMeasurementOffset(bool f) const;
    void measurementDateOffsetChanged(int o) const;
    void birthdayDateChanged(const QDateTime& d) const;
    void useBirthdayOffset(bool f) const;
    void birthdayOffsetChanged(int o) const;
    void subjectHisIdChanged(const QString& text) const;

private slots:

    void checkboxBruteModeChanged();
    void checkBoxMeasurementDateOffsetStateChanged(int arg1);
    void checkBoxBirthdayDateOffsetStateChanged(int arg1);

    void lineEditInFileEditingFinished();
    void lineEditOutFileEditingFinished();

    void dateTimeMeasurementDateDateTimeChanged(const QDateTime &dateTime);
    void spinBoxMeasurementDateOffsetValueChanged(int arg1);
    void dateTimeBirthdayDateDateTimeChanged(const QDateTime &dateTime);
    void spinBoxBirthdayDateOffsetValueChanged(int arg1);
    void lineEditSubjectHisIdEditingFinished();

    void openInFileDialog();
    void openOutFileDialog();

    void helpButtonClicked();

private:

    bool confirmClose();

    void setDefautlStateUi();

    void setupConnections();

    void idMeasurementDateChanged();

    void clearInfo();

//    bool m_bHideInfoFields;
    Ui::MainWindow* m_pUi;
    SettingsControllerGui* m_pController;
};

}
#endif // MNEANONYMIZE_MAINWINDOW_H