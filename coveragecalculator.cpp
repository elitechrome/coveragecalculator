#include "coveragecalculator.h"
#include "./ui_coveragecalculator.h"
#include <qfiledialog.h>
#include <qimagereader.h>
#include <QGraphicsPixmapItem>
#include "graphics_view_zoom.h"
#include <qdebug.h>

CoverageCalculator::CoverageCalculator(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CoverageCalculator)
{
    ui->setupUi(this);
    Graphics_view_zoom* z = new Graphics_view_zoom(ui->coverageView);
    z->set_modifiers(Qt::NoModifier);
}

CoverageCalculator::~CoverageCalculator()
{
    delete ui;
}


void CoverageCalculator::on_OpenButton_clicked()
{
    QString dataPath = QFileDialog::getExistingDirectory(nullptr, ("Select Output Folder"), QDir::currentPath());
    qDebug() << dataPath;
    if (dataPath.size() < 0)
    {
        qDebug() << "no folder is available.";
    }
    // check files exist
    QStringList loadFileName = {"Boundary.png",
                                "boundary_data.csv",
                                "path.csv",
                                "coverage_data.csv",
                               };
    for (auto file : loadFileName)
    {
        if (!QFile::exists(dataPath + file))
        {
            qDebug() << file << " is not found in " << dataPath;
            //exit.
        }
    }
    QGraphicsScene *scene = new QGraphicsScene;

    QImage map(1, 1, QImage::Format_Grayscale8);
    QImageReader reader(dataPath + "/" + loadFileName[0]);
    if (reader.read(&map)) {
        // Display icon
        QGraphicsPixmapItem *item = new QGraphicsPixmapItem(QPixmap::fromImage(map));
        scene->addItem(item);

        ui->coverageView->setScene(scene);
    }


}
class BoundaryMap
{
public:
    BoundaryMap(const QString& filePath);
    BoundaryMap(const BoundaryMap& map);
private:
    //img data
    //traj
};
class Pose2D
{
private:
    double x;
    double y;
    double w;
};
