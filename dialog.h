#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "gdcmImageReader.h"
#include <QImage>
#include <QImageWriter>
#include <QDropEvent>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QFileSystemWatcher>
#include <QDebug>
#include <utility>
#include <tuple>
#include <QFile>


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();


private slots:
    void FindFile();
    void directoryChanged(const QString & path);
    // Dicom annotation
    void dicom_Annotation();

protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);

    /* void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *);*/

private:
    /* For internal use only */
    //Convert Dicom to Qt image format
    bool ConvertToFormat_RGB888(gdcm::Image const & gimage, char *buffer, QImage *&imageQt);
    // String parser
    void stringParser(std::string s, double *outputMatrix, size_t size);

    // Image orientation
    char* getOrientation_H(double orientation_Matrix[]);
    char* getOrientation_V(double orientation_Matrix[]);

    // Drop event
    void FindFile_dropped(QString filename);

    // Image annotation functions
    std::pair<double, double> pix_3d_ptsfrom3d( double newlinept1xyz[], double newlinenorm[],
                                                double TLC_XYZmm[], double BRC_XYZmm[], double TRC_XYZmm[],
                                                double Im_rowdircoldir[], double thisPixSizeLocalYX[], double *newlineintersect_XYZmm);

    std::tuple<double, double, double, double> precise_phys_virt_na_dist(double thisFOVmm_LocalYX[], double thisPixSizeLocalYX[], double ImageNcols, double ImageNrows ,
                                                                         double TLC_XYZmm[], double TRC_XYZmm[] , double BRC_XYZmm[], double  ImageNormal[] , double Im_rowdircoldir[],
                                                                         double one_XYZ_pLPH[], double one_IJK_pLPH[]);


    QFileSystemWatcher * watcher;
    Ui::Dialog *ui;
    // QImage *imageQt_Scaled;
    float m_nInitialX, m_nInitialY, m_nFinalX, m_nFinalY;
    bool m_nbMousePressed;

    // Log file
    QFile *myFile;
    QTextStream myLog();
    QString Image_path, Log_path;
    QPolygonF arrowHead;
    QLineF line;
};

#endif // DIALOG_H
