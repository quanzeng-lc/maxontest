#include <QScreen>
#include "mainwindow.h"
#include <QDebug>
#include <QGuiApplication>
#include <QCloseEvent>


//! ---------------------------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief MainWindow::MainWindow
//!
MainWindow::MainWindow(){

    QScreen *screen=QGuiApplication::primaryScreen ();
    QRect mm=screen->availableGeometry() ;
    int screen_width = mm.width();
    int screen_height = mm.height();

    int window_width = screen_width*2/3;
    int window_height  =screen_height*2/3;
    int width_scale = window_width / 50;
    int height_scale = window_height / 50;
//    this->setFixedSize(QSize(window_width, window_height));
//    this->setGeometry(0, 0, window_width, window_height);
    this->setStyleSheet("background: gray");

    //! motor1
    this->maxon_motor1_label = new QLabel(this);
    this->maxon_motor1_label->setGeometry(0.5*width_scale, 0.5*height_scale, 3*width_scale, 2*height_scale);
    this->maxon_motor1_label->setText("motor1");
    this->maxon_motor1_position_label = new QLabel(this);
    this->maxon_motor1_position_label->setGeometry(5*width_scale, 0.5*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor1_position_label->setText("pos(mm)");
    this->maxon_motor1_position_label->setAlignment(Qt::AlignCenter);
    this->maxon_motor1_velocity_label = new QLabel(this);
    this->maxon_motor1_velocity_label->setText("vel(mm/s)");
    this->maxon_motor1_velocity_label->setGeometry(11*width_scale, 0.5*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor1_velocity_label->setAlignment(Qt::AlignCenter);
    this->maxon_motor1_enable_button = new QPushButton(this);
    this->maxon_motor1_enable_button->setGeometry(0.5*width_scale, 4*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor1_enable_button->setStyleSheet("background: green");
    this->maxon_motor1_enable_button->setText("disable");
    this->maxon_motor1_current_position = new QLabel(this);
    this->maxon_motor1_current_position->setGeometry(5*width_scale, 4*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor1_current_position->setText("0");
    this->maxon_motor1_current_position->setStyleSheet("background: green");
    this->maxon_motor1_current_position->setAlignment(Qt::AlignCenter);
    this->maxon_motor1_current_velocity = new QLabel(this);
    this->maxon_motor1_current_velocity->setText("0");
    this->maxon_motor1_current_velocity->setGeometry(11*width_scale, 4*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor1_current_velocity->setStyleSheet("background: green");
    this->maxon_motor1_current_velocity->setAlignment(Qt::AlignCenter);
    this->maxon_motor1_profileVelocitymode_button = new QPushButton(this);
    this->maxon_motor1_profileVelocitymode_button->setGeometry(0.5*width_scale, 9*height_scale, 7*width_scale, 2*height_scale);
    this->maxon_motor1_profileVelocitymode_button->setText("规划速度模式");
    this->maxon_motor1_profileVelocitymode_setVelocity_label = new QLabel(this);
    this->maxon_motor1_profileVelocitymode_setVelocity_label->setGeometry(0.5*width_scale, 12*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor1_profileVelocitymode_setVelocity_label->setText("设置速度");
    this->maxon_motor1_profileVelocitymode_setVelocity_text = new QLineEdit(this);
    this->maxon_motor1_profileVelocitymode_setVelocity_text->setGeometry(5*width_scale, 12*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor1_profileVelocitymode_setVelocity_text->setText(QString("0"));
    this->maxon_motor1_profileVelocitymode_setVelocity_text->setAlignment(Qt::AlignCenter);
    this->maxon_motor1_profileVelocitymode_setVelocity_text->setStyleSheet("background: green");
    this->maxon_motor1_profileVelocitymode_unit_label = new QLabel(this);
    this->maxon_motor1_profileVelocitymode_unit_label->setGeometry(10*width_scale, 12*height_scale, 2*width_scale, 2*height_scale);
    this->maxon_motor1_profileVelocitymode_unit_label->setText("mm/s");
    this->maxon_motor1_profileVelocitymode_startmove_button = new QPushButton(this);
    this->maxon_motor1_profileVelocitymode_startmove_button->setGeometry(0.5*width_scale, 15*height_scale, 7*width_scale, 2*height_scale);
    this->maxon_motor1_profileVelocitymode_startmove_button->setText(QString("velocity移动"));
    this->maxon_motor1_profileVelocitymode_startmove_button->setStyleSheet("background: green");
    this->maxon_motor1_profileVelocitymode_stop_button = new QPushButton(this);
    this->maxon_motor1_profileVelocitymode_stop_button->setGeometry(8*width_scale, 15*height_scale, 7*width_scale, 2*height_scale);
    this->maxon_motor1_profileVelocitymode_stop_button->setText(QString("velocity停止"));
    this->maxon_motor1_profileVelocitymode_stop_button->setStyleSheet("background: green");
    this->maxon_motor1_positionmode_button = new QPushButton(this);
    this->maxon_motor1_positionmode_button->setGeometry(0.5*width_scale, 22*height_scale, 7*width_scale, 2*height_scale);
    this->maxon_motor1_positionmode_button->setText("规划位置模式");
    this->maxon_motor1_absposition_radiaoButton = new QRadioButton(this);
    this->maxon_motor1_absposition_radiaoButton->setGeometry(0.5*width_scale, 25*height_scale, 1*width_scale, 2*height_scale);
    this->maxon_motor1_absposition_label = new QLabel(this);
    this->maxon_motor1_absposition_label->setGeometry(2*width_scale, 25*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor1_absposition_label->setText("绝对位置");
    this->maxon_motor1_absposition_text = new QLineEdit(this);
    this->maxon_motor1_absposition_text->setGeometry(6.5*width_scale, 25*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor1_absposition_text->setText(QString("0"));
    this->maxon_motor1_absposition_text->setAlignment(Qt::AlignCenter);
    this->maxon_motor1_absposition_text->setStyleSheet("background: green");
    this->maxon_motor1_asbposition_unit_label = new QLabel(this);
    this->maxon_motor1_asbposition_unit_label->setGeometry(11.5*width_scale, 25*height_scale, 2*width_scale, 2*height_scale);
    this->maxon_motor1_asbposition_unit_label->setText("mm");
    this->maxon_motor1_absposition_radiaoButton = new QRadioButton(this);
    this->maxon_motor1_absposition_radiaoButton->setGeometry(0.5*width_scale, 28*height_scale, 1*width_scale, 2*height_scale);
    this->maxon_motor1_relposition_label = new QLabel(this);
    this->maxon_motor1_relposition_label->setGeometry(2*width_scale, 28*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor1_relposition_label->setText("相对位置");
    this->maxon_motor1_relposition_text = new QLineEdit(this);
    this->maxon_motor1_relposition_text->setGeometry(6.5*width_scale, 28*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor1_relposition_text->setText(QString("0"));
    this->maxon_motor1_relposition_text->setAlignment(Qt::AlignCenter);
    this->maxon_motor1_relposition_text->setStyleSheet("background: green");
    this->maxon_motor1_relposition_unit_label = new QLabel(this);
    this->maxon_motor1_relposition_unit_label->setGeometry(11.5*width_scale, 28*height_scale, 2*width_scale, 2*height_scale);
    this->maxon_motor1_relposition_unit_label->setText("mm");
    this->maxon_motor1_positionmode_velocity_label = new QLabel(this);
    this->maxon_motor1_positionmode_velocity_label->setGeometry(0.5*width_scale, 31*height_scale, 2*width_scale, 2*height_scale);
    this->maxon_motor1_positionmode_velocity_label->setText("速度");
    this->maxon_motor1_positionmode_velocity_text = new QLineEdit(this);
    this->maxon_motor1_positionmode_velocity_text->setGeometry(3.5*width_scale, 31*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor1_positionmode_velocity_text->setText(QString("0"));
    this->maxon_motor1_positionmode_velocity_text->setAlignment(Qt::AlignCenter);
    this->maxon_motor1_positionmode_velocity_text->setStyleSheet("background: green");
    this->maxon_motor1_asbposition_velocity_unit_label = new QLabel(this);
    this->maxon_motor1_asbposition_velocity_unit_label->setGeometry(8.5*width_scale, 31*height_scale, 2*width_scale, 2*height_scale);
    this->maxon_motor1_asbposition_velocity_unit_label->setText("mm/s");
    this->maxon_motor1_asbpositionmode_startmove_button = new QPushButton(this);
    this->maxon_motor1_asbpositionmode_startmove_button->setGeometry(0.5*width_scale, 34.5*height_scale, 7*width_scale, 2*height_scale);
    this->maxon_motor1_asbpositionmode_startmove_button->setText("asbpos移动");
    this->maxon_motor1_asbpositionmode_startmove_button->setStyleSheet("background: green");
    this->maxon_motor1_positionmode_halt_button = new QPushButton(this);
    this->maxon_motor1_positionmode_halt_button->setGeometry(8*width_scale, 34.5*height_scale, 7*width_scale, 2*height_scale);
    this->maxon_motor1_positionmode_halt_button->setText("position停止");
    this->maxon_motor1_positionmode_halt_button->setStyleSheet("background: green");
    this->maxon_motor1_relpositionmode_startmove_button = new QPushButton(this);
    this->maxon_motor1_relpositionmode_startmove_button->setGeometry(0.5*width_scale, 37.5*height_scale, 7*width_scale, 2*height_scale);
    this->maxon_motor1_relpositionmode_startmove_button->setText("relpos移动");
    this->maxon_motor1_relpositionmode_startmove_button->setStyleSheet("background: green");

    this->maxon_motor1_velocitymode_button = new QPushButton(this);
    this->maxon_motor1_velocitymode_button->setGeometry(0.5*width_scale, 45*height_scale, 7*width_scale, 2*height_scale);
    this->maxon_motor1_velocitymode_button->setText("速度模式");
    this->maxon_motor1_velocitymode_setVelocity_label = new QLabel(this);
    this->maxon_motor1_velocitymode_setVelocity_label->setGeometry(0.5*width_scale, 48*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor1_velocitymode_setVelocity_label->setText("设置速度");
    this->maxon_motor1_velocitymode_setVelocity_text = new QLineEdit(this);
    this->maxon_motor1_velocitymode_setVelocity_text->setGeometry(5*width_scale, 48*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor1_velocitymode_setVelocity_text->setText(QString("0"));
    this->maxon_motor1_velocitymode_setVelocity_text->setAlignment(Qt::AlignCenter);
    this->maxon_motor1_velocitymode_setVelocity_text->setStyleSheet("background: green");
    this->maxon_motor1_velocitymode_unit_label = new QLabel(this);
    this->maxon_motor1_velocitymode_unit_label->setGeometry(10*width_scale, 48*height_scale, 2*width_scale, 2*height_scale);
    this->maxon_motor1_velocitymode_unit_label->setText("mm/s");
    this->maxon_motor1_velocitymode_startmove_button = new QPushButton(this);
    this->maxon_motor1_velocitymode_startmove_button->setGeometry(0.5*width_scale, 51*height_scale, 7*width_scale, 2*height_scale);
    this->maxon_motor1_velocitymode_startmove_button->setText(QString("velocity移动"));
    this->maxon_motor1_velocitymode_startmove_button->setStyleSheet("background: green");
    this->maxon_motor1_velocitymode_stop_button = new QPushButton(this);
    this->maxon_motor1_velocitymode_stop_button->setGeometry(8*width_scale, 51*height_scale, 7*width_scale, 2*height_scale);
    this->maxon_motor1_velocitymode_stop_button->setText(QString("velocity停止"));
    this->maxon_motor1_velocitymode_stop_button->setStyleSheet("background: green");


    //! motor2
    this->maxon_motor2_label = new QLabel(this);
    this->maxon_motor2_label->setGeometry(20*width_scale, 0.5*height_scale, 3*width_scale, 2*height_scale);
    this->maxon_motor2_label->setText("motor2");
    this->maxon_motor2_position_label = new QLabel(this);
    this->maxon_motor2_position_label->setGeometry(24.5*width_scale, 0.5*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor2_position_label->setText("pos(mm)");
    this->maxon_motor2_position_label->setAlignment(Qt::AlignCenter);
    this->maxon_motor2_velocity_label = new QLabel(this);
    this->maxon_motor2_velocity_label->setText("vel(mm/s)");
    this->maxon_motor2_velocity_label->setGeometry(30.5*width_scale, 0.5*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor2_velocity_label->setAlignment(Qt::AlignCenter);
    this->maxon_motor2_enable_button = new QPushButton(this);
    this->maxon_motor2_enable_button->setGeometry(20*width_scale, 4*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor2_enable_button->setStyleSheet("background: green");
    this->maxon_motor2_enable_button->setText("disable");
    this->maxon_motor2_current_position = new QLabel(this);
    this->maxon_motor2_current_position->setGeometry(24.5*width_scale, 4*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor2_current_position->setText("0");
    this->maxon_motor2_current_position->setStyleSheet("background: green");
    this->maxon_motor2_current_position->setAlignment(Qt::AlignCenter);
    this->maxon_motor2_current_velocity = new QLabel(this);
    this->maxon_motor2_current_velocity->setText("0");
    this->maxon_motor2_current_velocity->setGeometry(30.5*width_scale, 4*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor2_current_velocity->setStyleSheet("background: green");
    this->maxon_motor2_current_velocity->setAlignment(Qt::AlignCenter);
    this->maxon_motor2_velocitymode_button = new QPushButton(this);
    this->maxon_motor2_velocitymode_button->setGeometry(20*width_scale, 9*height_scale, 7*width_scale, 2*height_scale);
    this->maxon_motor2_velocitymode_button->setText("规划速度模式");
    this->maxon_motor2_velocitymode_setVelocity_label = new QLabel(this);
    this->maxon_motor2_velocitymode_setVelocity_label->setGeometry(20*width_scale, 12*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor2_velocitymode_setVelocity_label->setText("设置速度");
    this->maxon_motor2_velocitymode_setVelocity_text = new QLineEdit(this);
    this->maxon_motor2_velocitymode_setVelocity_text->setGeometry(24.5*width_scale, 12*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor2_velocitymode_setVelocity_text->setText(QString("0"));
    this->maxon_motor2_velocitymode_setVelocity_text->setAlignment(Qt::AlignCenter);
    this->maxon_motor2_velocitymode_setVelocity_text->setStyleSheet("background: green");
    this->maxon_motor2_velocitymode_unit_label = new QLabel(this);
    this->maxon_motor2_velocitymode_unit_label->setGeometry(29.5*width_scale, 12*height_scale, 2*width_scale, 2*height_scale);
    this->maxon_motor2_velocitymode_unit_label->setText("mm/s");
    this->maxon_motor2_velocitymode_startmove_button = new QPushButton(this);
    this->maxon_motor2_velocitymode_startmove_button->setGeometry(20*width_scale, 15*height_scale, 7*width_scale, 2*height_scale);
    this->maxon_motor2_velocitymode_startmove_button->setText(QString("velocity移动"));
    this->maxon_motor2_velocitymode_startmove_button->setStyleSheet("background: green");
    this->maxon_motor2_velocitymode_stop_button = new QPushButton(this);
    this->maxon_motor2_velocitymode_stop_button->setGeometry(27.5*width_scale, 15*height_scale, 7*width_scale, 2*height_scale);
    this->maxon_motor2_velocitymode_stop_button->setText(QString("velocity停止"));
    this->maxon_motor2_velocitymode_stop_button->setStyleSheet("background: green");
    this->maxon_motor2_positionmode_button = new QPushButton(this);
    this->maxon_motor2_positionmode_button->setGeometry(20*width_scale, 22*height_scale, 7*width_scale, 2*height_scale);
    this->maxon_motor2_positionmode_button->setText("规划位置模式");
    this->maxon_motor2_absposition_radiaoButton = new QRadioButton(this);
    this->maxon_motor2_absposition_radiaoButton->setGeometry(20*width_scale, 25*height_scale, 1*width_scale, 2*height_scale);
    this->maxon_motor2_absposition_label = new QLabel(this);
    this->maxon_motor2_absposition_label->setGeometry(21.5*width_scale, 25*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor2_absposition_label->setText("绝对位置");
    this->maxon_motor2_absposition_text = new QLineEdit(this);
    this->maxon_motor2_absposition_text->setGeometry(26*width_scale, 25*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor2_absposition_text->setText(QString("0"));
    this->maxon_motor2_absposition_text->setAlignment(Qt::AlignCenter);
    this->maxon_motor2_absposition_text->setStyleSheet("background: green");
    this->maxon_motor2_asbposition_unit_label = new QLabel(this);
    this->maxon_motor2_asbposition_unit_label->setGeometry(31*width_scale, 25*height_scale, 2*width_scale, 2*height_scale);
    this->maxon_motor2_asbposition_unit_label->setText("mm");
    this->maxon_motor2_absposition_radiaoButton = new QRadioButton(this);
    this->maxon_motor2_absposition_radiaoButton->setGeometry(20*width_scale, 28*height_scale, 1*width_scale, 2*height_scale);
    this->maxon_motor2_relposition_label = new QLabel(this);
    this->maxon_motor2_relposition_label->setGeometry(21.5*width_scale, 28*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor2_relposition_label->setText("相对位置");
    this->maxon_motor2_relposition_text = new QLineEdit(this);
    this->maxon_motor2_relposition_text->setGeometry(26*width_scale, 28*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor2_relposition_text->setText(QString("0"));
    this->maxon_motor2_relposition_text->setAlignment(Qt::AlignCenter);
    this->maxon_motor2_relposition_text->setStyleSheet("background: green");
    this->maxon_motor2_relposition_unit_label = new QLabel(this);
    this->maxon_motor2_relposition_unit_label->setGeometry(31*width_scale, 28*height_scale, 2*width_scale, 2*height_scale);
    this->maxon_motor2_relposition_unit_label->setText("mm");
    this->maxon_motor2_positionmode_velocity_label = new QLabel(this);
    this->maxon_motor2_positionmode_velocity_label->setGeometry(20*width_scale, 31*height_scale, 2*width_scale, 2*height_scale);
    this->maxon_motor2_positionmode_velocity_label->setText("速度");
    this->maxon_motor2_positionmode_velocity_text = new QLineEdit(this);
    this->maxon_motor2_positionmode_velocity_text->setGeometry(23*width_scale, 31*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor2_positionmode_velocity_text->setText(QString("0"));
    this->maxon_motor2_positionmode_velocity_text->setAlignment(Qt::AlignCenter);
    this->maxon_motor2_positionmode_velocity_text->setStyleSheet("background: green");
    this->maxon_motor2_asbposition_velocity_unit_label = new QLabel(this);
    this->maxon_motor2_asbposition_velocity_unit_label->setGeometry(28*width_scale, 31*height_scale, 2*width_scale, 2*height_scale);
    this->maxon_motor2_asbposition_velocity_unit_label->setText("mm/s");
    this->maxon_motor2_asbpositionmode_startmove_button = new QPushButton(this);
    this->maxon_motor2_asbpositionmode_startmove_button->setGeometry(20*width_scale, 34.5*height_scale, 7*width_scale, 2*height_scale);
    this->maxon_motor2_asbpositionmode_startmove_button->setText("asbpos移动");
    this->maxon_motor2_asbpositionmode_startmove_button->setStyleSheet("background: green");
    this->maxon_motor2_positionmode_halt_button = new QPushButton(this);
    this->maxon_motor2_positionmode_halt_button->setGeometry(27.5*width_scale, 34.5*height_scale, 7*width_scale, 2*height_scale);
    this->maxon_motor2_positionmode_halt_button->setText("position停止");
    this->maxon_motor2_positionmode_halt_button->setStyleSheet("background: green");
    this->maxon_motor2_relpositionmode_startmove_button = new QPushButton(this);
    this->maxon_motor2_relpositionmode_startmove_button->setGeometry(20*width_scale, 37.5*height_scale, 7*width_scale, 2*height_scale);
    this->maxon_motor2_relpositionmode_startmove_button->setText("relpos移动");
    this->maxon_motor2_relpositionmode_startmove_button->setStyleSheet("background: green");

    this->hitParticle_button = new QPushButton(this);
    this->hitParticle_button->setGeometry(20*width_scale, 41*height_scale, 7*width_scale, 2*height_scale);
    this->hitParticle_button->setText("hit Particle");
    this->hitParticle_button->setStyleSheet("background: green");

    //! enable
    this->maxon_motor_enable_button = new QPushButton(this);
    this->maxon_motor_enable_button->setGeometry(40*width_scale, 0.5*height_scale, 8*width_scale, 4*height_scale);
    this->maxon_motor_enable_button->setText(QString("打开伺服"));
    this->maxon_motor_enable_button->setStyleSheet("background: green");

    this->omage_test_button = new QPushButton(this);
    this->omage_test_button->setGeometry(40*width_scale, 5*height_scale, 8*width_scale, 4*height_scale);
    this->omage_test_button->setText(QString("omega"));
    this->omage_test_button->setStyleSheet("background: green");

    this->gravityButton = new QPushButton(this);
    this->gravityButton->setGeometry(40*width_scale, 10*height_scale, 8*width_scale, 4*height_scale);
    this->gravityButton->setText(QString("gravity"));
    this->gravityButton->setStyleSheet("background: green");

    this->startFollowControlButton = new QPushButton(this);
    this->startFollowControlButton->setGeometry(40*width_scale, 15*height_scale, 8*width_scale, 4*height_scale);
    this->startFollowControlButton->setText(QString("Start Follow"));
    this->startFollowControlButton->setStyleSheet("background: green");


    //force show
    this->forceSensorLabel = new QLabel(this);
    this->forceSensorLabel->setGeometry(50*width_scale, 0.5*height_scale, 2*width_scale, 2*height_scale);
    this->forceSensorLabel->setText("Force");
    this->forceSensorLabel->setAlignment(Qt::AlignCenter);
    this->forceSensorShowLabel = new QLabel(this);
    this->forceSensorShowLabel->setGeometry(52.5*width_scale, 0.5*height_scale, 4*width_scale, 2*height_scale);
    this->forceSensorShowLabel->setText("0");
    this->forceSensorShowLabel->setAlignment(Qt::AlignCenter);
    this->forceSensorShowLabel->setStyleSheet("background: green");
    this->forceSensorLabel = new QLabel(this);
    this->forceSensorLabel->setGeometry(57*width_scale, 0.5*height_scale, 2*width_scale, 2*height_scale);
    this->forceSensorLabel->setText("mN");
    this->forceSensorLabel->setAlignment(Qt::AlignCenter);

    this->init();
}

void MainWindow::init(){
    maxonMotor1 = new MaxonMotor(1);
    this->maxonMotor1->SetDirection(false);
    maxonMotor1->initMachPara(1000*4, 33, 2);
    maxonMotor2 = new MaxonMotor(2);
    maxonMotor2->SetDirection(true);
    maxonMotor2->initMachPara(512*4, 19.2*1.33, 37.68);

    m_omegaFunc = new OmegaFunction();
    omega_win = new omega(m_omegaFunc);

    forceSensor = new ForceSensor("COM4", 9600, 'N', 8, 1);
    this->enableF = false;
    this->m_isFollow = false;
    this->m_done = true;

    this->interFaceInit();
    this->connect(maxon_motor1_enable_button, SIGNAL(clicked()), this, SLOT(motor1_enable()));
    this->connect(maxon_motor2_enable_button, SIGNAL(clicked()), this, SLOT(motor2_enable()));
    this->connect(maxon_motor1_profileVelocitymode_button, SIGNAL(clicked()), this, SLOT(set_motor1_profileVelmode()));
    this->connect(maxon_motor2_velocitymode_button, SIGNAL(clicked()), this, SLOT(set_motor2_ProfileVelMode()));
    this->connect(maxon_motor1_velocitymode_button, SIGNAL(clicked()), this, SLOT(set_motor1_velocityMode()));
    this->connect(maxon_motor1_velocitymode_startmove_button, SIGNAL(clicked()), this, SLOT(motor1_velocitymode_move()));
    this->connect(maxon_motor1_velocitymode_stop_button, SIGNAL(clicked()), this, SLOT(motor1_velocitymode_halt()));
    this->connect(maxon_motor1_profileVelocitymode_startmove_button, SIGNAL(clicked()), this, SLOT(motor1_profileVelocitymode_move()));
    this->connect(maxon_motor2_velocitymode_startmove_button, SIGNAL(clicked()), this, SLOT(motor2_velocitymode_move()));
    this->connect(maxon_motor1_profileVelocitymode_stop_button, SIGNAL(clicked()), this, SLOT(motor1_profileVelocitymode_halt()));
    this->connect(maxon_motor2_velocitymode_stop_button, SIGNAL(clicked()), this, SLOT(motor2_velocitymode_halt()));
    this->connect(maxon_motor1_positionmode_button, SIGNAL(clicked()), this, SLOT(set_motor1_profilePosmode()));
    this->connect(maxon_motor2_positionmode_button, SIGNAL(clicked()), this, SLOT(set_motor2_profilePosmode()));
    this->connect(maxon_motor1_asbpositionmode_startmove_button, SIGNAL(clicked()), this, SLOT(motor1_profilePosAbsmove()));
    this->connect(maxon_motor2_asbpositionmode_startmove_button, SIGNAL(clicked()), this, SLOT(motor2_profilePosAbsmove()));
    this->connect(maxon_motor1_relpositionmode_startmove_button, SIGNAL(clicked()), this, SLOT(motor1_profilePosRelmove()));
    this->connect(maxon_motor2_relpositionmode_startmove_button, SIGNAL(clicked()), this, SLOT(motor2_profilePosRelmove()));
    this->connect(maxon_motor1_positionmode_halt_button, SIGNAL(clicked()), this, SLOT(motor1_profilePoshalt()));
    this->connect(maxon_motor2_positionmode_halt_button, SIGNAL(clicked()), this, SLOT(motor2_profilePoshalt()));
    this->connect(maxon_motor1_velocitymode_startmove_button, SIGNAL(clicked()), this, SLOT(motor1_velocitymode_move()));
    this->connect(hitParticle_button, SIGNAL(clicked()), this, SLOT(hit_particle()));
    this->connect(omage_test_button, SIGNAL(clicked()), this, SLOT(omega_show()));
    this->connect(gravityButton, SIGNAL(clicked()), this, SLOT(startGravity()));
    this->connect(startFollowControlButton, SIGNAL(clicked()), this, SLOT(startFollowControl()));

    this->connect(this->paraShowTimer, SIGNAL(timeout()), this, SLOT(showPara()));
}

MainWindow::~MainWindow(){
    this->maxonMotor1->closeDevice();
    this->maxonMotor2->closeDevice();
}
void MainWindow::interFaceInit(){
    this->maxon_motor_enable_button->setDisabled(true);
    //to do ...
    this->maxon_motor1_asbpositionmode_startmove_button->setDisabled(true);
    this->maxon_motor1_relpositionmode_startmove_button->setDisabled(true);
    this->maxon_motor1_positionmode_halt_button->setDisabled(true);
    this->maxon_motor2_asbpositionmode_startmove_button->setDisabled(true);
    this->maxon_motor2_relpositionmode_startmove_button->setDisabled(true);
    this->maxon_motor2_positionmode_halt_button->setDisabled(true);
    this->hitParticle_button->setDisabled(true);
    this->startFollowControlButton->setDisabled(true);
    this->maxon_motor1_velocitymode_startmove_button->setDisabled(true);
    this->maxon_motor1_velocitymode_stop_button->setDisabled(true);
    this->paraShowTimer = new QTimer();
    this->paraShowTimer->start(100);
}

void MainWindow::showPara(){
    double currentPos = maxonMotor1->getCurrentPosition();
    double currentVel = maxonMotor1->getCurrentVelocity();
    maxon_motor1_current_position->setText(QString::number(currentPos));
    maxon_motor1_current_velocity->setText(QString::number(currentVel));

    double currentPos2 = maxonMotor2->getCurrentPosition();
    double currentVel2 = maxonMotor2->getCurrentVelocity();
    maxon_motor2_current_position->setText(QString::number(currentPos2));
    maxon_motor2_current_velocity->setText(QString::number(currentVel2));

    int force = forceSensor->getCalForce();
    forceSensorShowLabel->setText(QString::number(force));
}

void MainWindow::omega_show(){
    omega_win->show();
}

bool MainWindow::enable(){
    qDebug()<<"enable";
    if(this->enableF){
        if(this->maxonMotor2->enable()&&this->maxonMotor2->enable()){
            this->enableF = true;
            this->maxon_motor_enable_button->setText("关闭使能");
            return true;
        }
        else{
            qDebug()<<"can't enable!";
            return false;
        }
    }
    else{
        if(this->maxonMotor2->disable()&&this->maxonMotor2->disable()){
            this->enableF = false;
            this->maxon_motor_enable_button->setText("打开使能");
            return true;
        }
        else{
            qDebug()<<"failed disable!";
            return false;
        }
    }
}

bool MainWindow::motor1_enable(){
    if(this->maxonMotor1->enableIs()){
        if(this->maxonMotor1->disable()){
            this->maxon_motor1_enable_button->setText("disable");
            return true;
        }else{
            qDebug()<<"failed disable!";
            return false;
        }

    }else{
      if(this->maxonMotor1->enable()){
          this->maxon_motor1_enable_button->setText("enable");
          return true;
      }else{
          qDebug()<<"can't enable!";
          return false;
      }
    }
}

bool MainWindow::set_motor1_profileVelmode(){
    if(0 != this->maxonMotor1->m_bMode){
        if(this->maxonMotor1->setProfileVelocityMode()){
            this->maxon_motor1_profileVelocitymode_startmove_button->setDisabled(false);
            this->maxon_motor1_profileVelocitymode_stop_button->setDisabled(false);
            this->maxon_motor1_asbpositionmode_startmove_button->setDisabled(true);
            this->maxon_motor1_relpositionmode_startmove_button->setDisabled(true);
            this->maxon_motor1_positionmode_halt_button->setDisabled(true);
            this->maxon_motor1_velocitymode_startmove_button->setDisabled(true);
            this->maxon_motor1_velocitymode_stop_button->setDisabled(true);
            return true;
        }
        else{
            return false;
        }
    }
    return true;
}

bool MainWindow::motor1_profileVelocitymode_move(){
    float profileVelmodeVelocity = this->maxon_motor1_profileVelocitymode_setVelocity_text->text().toFloat();
    this->maxonMotor1->setProfileVelocityModeTargetVelocity(profileVelmodeVelocity);
    return this->maxonMotor1->ProfileVelocityStartMove();
}

bool MainWindow::motor1_profileVelocitymode_halt(){
    return this->maxonMotor1->ProfileVelocityHalt();
}

bool MainWindow::set_motor1_profilePosmode(){
    if(0 != this->maxonMotor1->m_bMode){
        if(this->maxonMotor1->setProfilePositionMode()){
            this->maxon_motor1_profileVelocitymode_startmove_button->setDisabled(true);
            this->maxon_motor1_profileVelocitymode_stop_button->setDisabled(true);
            this->maxon_motor1_asbpositionmode_startmove_button->setDisabled(false);
            this->maxon_motor1_relpositionmode_startmove_button->setDisabled(false);
            this->maxon_motor1_positionmode_halt_button->setDisabled(false);
            this->maxon_motor1_velocitymode_startmove_button->setDisabled(true);
            this->maxon_motor1_velocitymode_stop_button->setDisabled(true);
            return true;
        }
        else{
            return false;
        }
    }
    return true;
}

void MainWindow::motor1_profilePosAbsmove(){
    float position = maxon_motor1_absposition_text->text().toFloat();
    float velocity = maxon_motor1_positionmode_velocity_text->text().toFloat();
    this->maxonMotor1->setProfilePosPara(velocity, position);
    this->maxonMotor1->ProfilePositionStartMove();
}

void MainWindow::motor1_profilePosRelmove(){

}

void MainWindow::motor1_profilePoshalt(){
    maxonMotor1->ProfilePositionHalt();
}

bool MainWindow::set_motor1_velocityMode(){
    if(2 != this->maxonMotor1->m_bMode){
        if(this->maxonMotor1->setVelocityMode()){
            this->maxon_motor1_profileVelocitymode_startmove_button->setDisabled(true);
            this->maxon_motor1_profileVelocitymode_stop_button->setDisabled(true);
            this->maxon_motor1_asbpositionmode_startmove_button->setDisabled(true);
            this->maxon_motor1_relpositionmode_startmove_button->setDisabled(true);
            this->maxon_motor1_positionmode_halt_button->setDisabled(true);
            this->maxon_motor1_velocitymode_startmove_button->setDisabled(false);
            this->maxon_motor1_velocitymode_stop_button->setDisabled(false);
            return true;
        }
        else{
            return false;
        }
    }
    return true;
}

bool MainWindow::motor1_velocitymode_move(){
    qDebug()<<"velocityMode";
    float profileVelmodeVelocity = this->maxon_motor1_velocitymode_setVelocity_text->text().toFloat();
    return this->maxonMotor1->setVelocityModeVelocity(profileVelmodeVelocity);
}

bool MainWindow::motor1_velocitymode_halt(){
    return this->maxonMotor1->setQuickStopState();
}

bool MainWindow::motor2_enable(){
    if(this->maxonMotor2->enableIs()){
        if(this->maxonMotor2->disable()){
            this->maxon_motor2_enable_button->setText("disable");
            return true;
        }else{
            qDebug()<<"failed disable!";
            return false;
        }
    }else{
      if(this->maxonMotor2->enable()){
          this->maxon_motor2_enable_button->setText("enable");
          return true;
      }else{
            qDebug()<<"can't enable!";
            return false;
      }
    }
}

bool MainWindow::set_motor2_ProfileVelMode(){
    if(0 != this->maxonMotor2->m_bMode){
        if(this->maxonMotor2->setProfileVelocityMode()){
            this->maxon_motor2_velocitymode_startmove_button->setDisabled(false);
            this->maxon_motor2_velocitymode_stop_button->setDisabled(false);
            this->maxon_motor2_asbpositionmode_startmove_button->setDisabled(true);
            this->maxon_motor2_relpositionmode_startmove_button->setDisabled(true);
            this->maxon_motor2_positionmode_halt_button->setDisabled(true);
            this->hitParticle_button->setDisabled(true);
            return true;
        }
        else{
            return false;
        }
    }
    return true;
}

bool MainWindow::motor2_velocitymode_move(){
    float profileVelmodeVelocity = this->maxon_motor2_velocitymode_setVelocity_text->text().toFloat();
    this->maxonMotor2->setProfileVelocityModeTargetVelocity(profileVelmodeVelocity);
    return this->maxonMotor2->ProfileVelocityStartMove();
}

bool MainWindow::motor2_velocitymode_halt(){
    return this->maxonMotor2->ProfileVelocityHalt();
}

bool MainWindow::set_motor2_profilePosmode(){
    if(0 != this->maxonMotor2->m_bMode){
        if(this->maxonMotor2->setProfilePositionMode()){
            this->maxon_motor2_velocitymode_startmove_button->setDisabled(true);
            this->maxon_motor2_velocitymode_stop_button->setDisabled(true);
            this->maxon_motor2_asbpositionmode_startmove_button->setDisabled(false);
            this->maxon_motor2_relpositionmode_startmove_button->setDisabled(false);
            this->maxon_motor2_positionmode_halt_button->setDisabled(false);
            this->hitParticle_button->setDisabled(false);
            return true;
        }
        else{
            return false;
        }
    }
    return true;
}

void MainWindow::motor2_profilePosAbsmove(){
    float position = maxon_motor2_absposition_text->text().toFloat();
    float velocity = maxon_motor2_positionmode_velocity_text->text().toFloat();
    this->maxonMotor2->setProfilePosPara(velocity, position);
    this->maxonMotor2->ProfilePositionStartMove();
}

void MainWindow::motor2_profilePosRelmove(){

}

void MainWindow::motor2_profilePoshalt(){
    this->maxonMotor2->ProfilePositionHalt();
}

void MainWindow::hit_particle(){
    std::thread t = std::thread([=]{
        float position = maxon_motor2_absposition_text->text().toFloat();
        float velocity = maxon_motor2_positionmode_velocity_text->text().toFloat();
        this->maxonMotor2->setProfilePosPara(velocity, position);
        this->maxonMotor2->ProfilePositionStartMove();
    });
    t.detach();
}

bool MainWindow::halt(){
    return this->maxonMotor2->halt();
}

void MainWindow::go_to_pos1(){
//    coordinatesMovementMoudle->CoordinateMovementModuleMoveTo(758.364, 367.447, 49.646);
    this->maxonMotor2->startMove();
    qDebug()<<"go_pos1";
}

void MainWindow::closeEvent(QCloseEvent * e)
{
    delete omega_win;
    maxonMotor1->closeDevice();
    maxonMotor2->closeDevice();
//    delete maxonMotor1;
//    delete maxonMotor2;
    e->accept();
}


void MainWindow::startGravity(){
    if(m_isFollow) return;
    if(m_done){
        std::thread tForce(std::bind(&MainWindow::setForce, this));
        tForce.detach();
    }else{
        m_done = true;
    }
}

void MainWindow::setForce(){
    gravityButton->setText("running..");
    startFollowControlButton->setDisabled(false);
    m_done = false;
    double px, py, pz;
    double fx, fy, fz;
    double t1,t0  = dhdGetTime ();
    // open the first available device
    if (!m_omegaFunc->drdOpenOmega()) {
      dhdSleep (2.0);
      return;
    }
    if(!m_omegaFunc->omegaDrdIsSupport()) return;
    if(!m_omegaFunc->omegaDrdAutoInit()) return;
    else if(!m_omegaFunc->omegaDrdStart()) return;
    double nullPos[6] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    m_omegaFunc->omegaDrdMoveTo(nullPos);
    m_omegaFunc->omegaDrdStop(true);
    // haptic loop
    while (!m_done) {
      // apply zero force
      if (m_omegaFunc->omegaDrdSetForceAndTorqueAndGripperForce(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0) < DHD_NO_ERROR) {
        printf ("error: cannot set force (%s)\n", dhdErrorGetLastStr());
        m_done = true;
      }
      // display refresh rate and position at 10Hz
      t1 = dhdGetTime ();
      if ((t1-t0) > 0.01) {
        // update timestamp
        t0 = t1;
        if(m_isFollow){
            omegaFollow();
        }
      }
    }
    // close the connection
    m_omegaFunc->drdCloseOmega();

    gravityButton->setText("gravity");
    startFollowControlButton->setDisabled(true);
    // happily exit
    return;
}

void MainWindow::omegaFollow(){
    //to do....
    // e = (Xm - Xm0) - K(Xs - Xs0)
    double Kp = 1, Kd = 0.5, K = 10;
    double KdKInverse = 1/(Kd*K);
    double KInverse = 1/K;
    double XsSpeed = 0;
    double XmPos, YmPos, ZmPos;
    // retrieve position
    recordeOmegaPos(&XmPos, &YmPos, &ZmPos);
    double XmSpeed, YmSpeed, ZmSpeed;
    recordeOmegaVel(&XmSpeed, &YmSpeed, &ZmSpeed);
    double XsPos = maxonMotor1->getCurrentPosition();
    XsSpeed = KInverse*XmSpeed + KdKInverse*(Kp*(XmPos - XmPosInit) - K*(XsPos - XsPosInit));
//    qDebug()<<"XsSpeed: "<<XsSpeed;
    maxonMotor1->setVelocityModeVelocity(XsSpeed);
}

void MainWindow::startFollowControl(){
    if(!m_isFollow){
        bool rnt = maxonMotor1->enable();
        rnt = maxonMotor1->setVelocityMode();
        //quanzeng 2021.07.15 记录当前omega的当前位置
        recordeOmegaPos(&XmPosInit, &YmPosInit, &ZmPosInit);
        XsPosInit = maxonMotor1->getCurrentPosition();
        startFollowControlButton->setText("running..");
        m_isFollow = true;
//        qDebug()<<"XmPosInit:"<<XmPosInit<<" "<<"YmPosInit:"<<YmPosInit<<" "<<"ZmPosInit:"<<ZmPosInit<<"XsPosInit:"<<XsPosInit;
    }else{
        maxonMotor1->setQuickStopState();
        maxonMotor1->disable();

        startFollowControlButton->setText("Start Follow");
        m_isFollow = false;
    }
}

void MainWindow::recordeOmegaPos(double* XmPos, double* YmPos, double* ZmPos){
    double theta1, theta2, theta3, gPos;
    if (m_omegaFunc->omegaDrdGetPos(XmPos, YmPos, ZmPos, &theta1, &theta2, &theta3, &gPos) < DHD_NO_ERROR) {
        m_done = true;
    }
    *XmPos = *XmPos*1000;
    *YmPos = *YmPos*1000;
    *ZmPos = *ZmPos*1000;
}

void MainWindow::recordeOmegaVel(double* XmSpeed, double* YmSpeed, double* ZmSpeed){
    double theta1Vel, theta2Vel, theta3Vel, gVel;
    if (m_omegaFunc->omegaDrdGetVel(XmSpeed, YmSpeed, ZmSpeed, &theta1Vel, &theta2Vel, &theta3Vel, &gVel) < DHD_NO_ERROR) {
        m_done = true;
    }
    *XmSpeed = *XmSpeed*1000;
    *YmSpeed = *YmSpeed*1000;
    *ZmSpeed = *ZmSpeed*1000;
}

