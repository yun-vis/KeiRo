//******************************************************************************
// MainWindow.cpp
//	: program file for main window
//
//------------------------------------------------------------------------------
//
//	Ver 1.00		Date: Tue Jun 19 02:36:37 2019
//
//******************************************************************************

//------------------------------------------------------------------------------
//	Including Header Files
//------------------------------------------------------------------------------


#include "MainWindow.h"

namespace Ui {
	
	//------------------------------------------------------------------------------
    //	Private functions
    //------------------------------------------------------------------------------
    //
    //  MainWindow::_createActions -- create actions
    //
    //  Inputs
    //  none
    //
    //  Outputs
    //  none
    //
    void MainWindow::_createActions()
    {
        QMenu *fileMenu = menuBar()->addMenu(tr("&File"));

        // tool box setting
        QToolBar *fileToolBar = addToolBar(tr("File"));
        fileToolBar->setIconSize(QSize(25, 25));
        fileToolBar->setFixedHeight(50);
	
	    //------------------------------------------------------------------------------
	    //	tool box
	    //------------------------------------------------------------------------------
	    const QIcon newIcon = QIcon::fromTheme("", QIcon(":/icons/app.png"));
        QAction *newFileAct = new QAction(newIcon, tr("&Open"), this );
        newFileAct->setShortcuts( QKeySequence::New) ;
        newFileAct->setStatusTip(tr("Open a new file"));
        connect( newFileAct, &QAction::triggered, this, &MainWindow::newFile );
        fileMenu->addAction( newFileAct );
        fileToolBar->addAction( newFileAct );

#ifdef SKIP
        const QIcon saveIcon = QIcon::fromTheme("", QIcon(":/icons/save.png"));
        //const QIcon saveIcon = QIcon::fromTheme("document-save", QIcon(":/icons/save.png"));
        QAction *saveAct = new QAction( saveIcon, tr("&Save..."), this );
        saveAct->setShortcuts( QKeySequence::Save);
        saveAct->setStatusTip(tr("Save the current form letter") );
        connect( saveAct, &QAction::triggered, this, &MainWindow::save );
        fileMenu->addAction( saveAct );
        fileToolBar->addAction( saveAct );

        const QIcon printIcon = QIcon::fromTheme( "", QIcon(":/icons/print.png") );
        //const QIcon printIcon = QIcon::fromTheme("document-print", QIcon(":/icons/print.png"));
        QAction *printAct = new QAction(printIcon, tr("&Print..."), this);
        printAct->setShortcuts(QKeySequence::Print);
        printAct->setStatusTip(tr("Print the current form letter") );
        connect( printAct, &QAction::triggered, this, &MainWindow::print);
        fileMenu->addAction( printAct );
        fileToolBar->addAction( printAct );
#endif // SKIP

	    //------------------------------------------------------------------------------
	    //	file menu
	    //------------------------------------------------------------------------------

        fileMenu->addSeparator();

        QAction *quitAct = fileMenu->addAction( tr("&Quit"), this, &QWidget::close );
        quitAct->setShortcuts(QKeySequence::Quit);
        quitAct->setStatusTip(tr("Quit the application"));

        QMenu *editMenu = menuBar()->addMenu(tr("&Edit"));
        QToolBar *editToolBar = addToolBar(tr("Edit"));
        editToolBar->setIconSize(QSize(25, 25));
        editToolBar->setFixedHeight(50);

#ifdef SKIP
        const QIcon undoIcon = QIcon::fromTheme("", QIcon(":/icons/undo.png"));
        //const QIcon undoIcon = QIcon::fromTheme("edit-undo", QIcon(":/icons/undo.png"));
        QAction *undoAct = new QAction(undoIcon, tr("&Undo"), this);
        undoAct->setShortcuts(QKeySequence::Undo);
        undoAct->setStatusTip(tr("Undo the last editing action"));
        connect(undoAct, &QAction::triggered, this, &MainWindow::undo);
        editMenu->addAction(undoAct);
        editToolBar->addAction(undoAct);
#endif // SKIP
        
        menuBar()->addSeparator();

        _viewMenu = menuBar()->addMenu(tr("&View"));
        menuBar()->addSeparator();

        QMenu *helpMenu = menuBar()->addMenu(tr("&Help"));

        QAction *aboutAct = helpMenu->addAction(tr("&About"), this, &MainWindow::about );
        aboutAct->setStatusTip(tr("Show the application's About box"));

        QAction *aboutQtAct = helpMenu->addAction(tr("About &Qt"), qApp, &QApplication::aboutQt );
        aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
		
		connect( _mainGV, SIGNAL( dataInitialized() ), this, SLOT( _initAllDocks() ) );
        connect( _mainGV, SIGNAL( dataChanged() ), this, SLOT( _updateAllDocks() ) );
    }

    //
    //  MainWindow::_createStatusBar -- create status bar
    //
    //  Inputs
    //  none
    //
    //  Outputs
    //  none-'['-]
    //
    void MainWindow::_createStatusBar()
    {
        statusBar()->showMessage(tr("Ready"));
    }

    //
    //  MainWindow::_createDockWindows -- create dock windows
    //
    //  Inputs
    //  none
    //
    //  Outputs
    //  none
    //
//    void MainWindow::_createDockWindows( void )
//    {
//	    _settingsDock = new QDockWidget(tr("Setting"), this );
//        _settingsDock->setAllowedAreas( Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
//
//	    _setting = new QWidget( _settingsDock );
//        _setting->setGeometry( QRect(0,0,KeiRo::Base::Common::getDockWidgetWidth(),
//									 KeiRo::Base::Common::getMainwidgetHeight()/2.0 ) );
//        _setting->setMinimumSize( QSize( KeiRo::Base::Common::getDockWidgetWidth(),
//										 KeiRo::Base::Common::getMainwidgetHeight()/3.0 ) );
////	    _setting->setMaximumSize( QSize( KeiRo::Base::Common::getDockWidgetWidth(),
////	                                     KeiRo::Base::Common::getMainwidgetHeight()/3.0 ) );
////        _setting->setMouseTracking( false );
//        _settingsDock->setWidget( _setting );
//        addDockWidget(Qt::RightDockWidgetArea, _settingsDock );
//        _viewMenu->addAction(_settingsDock->toggleViewAction() );
//
//
//	    _interactionDock = new QDockWidget(tr("Interaction"), this );
//	    _interactionDock->setAllowedAreas( Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
//
//        _interaction = new QWidget( _interactionDock );
//        _interaction->setGeometry( QRect(0,0,KeiRo::Base::Common::getDockWidgetWidth(),
//										 KeiRo::Base::Common::getDockWidgetWidth()*KeiRo::Base::Common::getMainwidgetHeight()/KeiRo::Base::Common::getMainwidgetWidth() ) );
//        _interaction->setMinimumSize( QSize( KeiRo::Base::Common::getDockWidgetWidth(),
//											 KeiRo::Base::Common::getDockWidgetWidth()*KeiRo::Base::Common::getMainwidgetHeight()/KeiRo::Base::Common::getMainwidgetWidth() ) );
////        _interaction->setMouseTracking( false );
//
//	    _interactionDock->setWidget( _interaction );
//        addDockWidget(Qt::RightDockWidgetArea, _interactionDock );
//        _viewMenu->addAction( _interactionDock->toggleViewAction() );
//
//	    //    connect(setting, &QWidget::windowIconChanged, this, &MainWindow::updateSetting );
//	    //    connect(interaction, &QWidget::windowIconChanged, this, &MainWindow::updateInteraction );
//    }

    void MainWindow::setSettings(QWidget* settingsWidget) 
    {
    }
	
	void MainWindow::setInteraction(QWidget* interactionWidget)
	{
	}
	
    //------------------------------------------------------------------------------
    //	Protected functions
    //------------------------------------------------------------------------------
    //
    //  MainWindow::initSetting -- init setting
    //
    //  Inputs
    //  setting: text string
    //
    //  Outputs
    //  none
    //
    void MainWindow::_initSetting( const QString &setting )
    {
//    	_setting->initSceneItems();
	    if( setting.isEmpty() ) return;
    }
	
	//
	//  MainWindow::initInteraction -- init interaction
	//
	//  Inputs
	//  interaction: text string
	//
	//  Outputs
	//  none
	//
	void MainWindow::_initInteraction( const QString &interaction )
	{
		_interaction->initSceneItems();
		if( interaction.isEmpty() ) return;
	}
	
	//
	//  MainWindow::_initAllDocks -- init all dock widgets
	//
	//  Inputs
	//  none
	//
	//  Outputs
	//  none
	//
	void MainWindow::_initAllDocks( void )
	{
		_initSetting( "" );
		_initInteraction( "" );
//		cerr << "init docks..." << endl;
	}
	
	//
    //  MainWindow::updateSetting -- update setting
    //
    //  Inputs
    //  setting: text string
    //
    //  Outputs
    //  none
    //
    void MainWindow::_updateSetting( const QString &setting )
    {
//    	_setting->updateSceneItems();
        if( setting.isEmpty() ) return;
    }

    //
    //  MainWindow::updateInteraction -- update interaction
    //
    //  Inputs
    //  interaction: text string
    //
    //  Outputs
    //  none
    //
    void MainWindow::_updateInteraction( const QString &interaction )
    {
        _interaction->updateSceneItems();
        if( interaction.isEmpty() ) return;
    }

    //
    //  MainWindow::_updateAllDocks -- update all dock widgets
    //
    //  Inputs
    //  none
    //
    //  Outputs
    //  none
    //
    void MainWindow::_updateAllDocks( void )
    {
        _updateSetting( "" );
        _updateInteraction( "" );
//        cerr << "update docks..." << endl;
    }

    //------------------------------------------------------------------------------
    //	Public functions
    //------------------------------------------------------------------------------
    //------------------------------------------------------------------------------
    //	Constructors & Destructors
    //------------------------------------------------------------------------------
    //
    //  MainWindow::MainWindow -- constructor
    //
    //  Inputs
    //  parent: parent widget
    //
    //  Outputs
    //  none
    //
    MainWindow::MainWindow( QWidget *parent )
        : QMainWindow( parent )
    {
	    //------------------------------------------------------------------------------
	    // initialization
	    //------------------------------------------------------------------------------
	    _basePtr = nullptr;
	    
	    // setup timer
	    _timerptr = new QTimer( this );
	    connect( _timerptr, SIGNAL( timeout() ), this, SLOT( exportPNG() ) );
	    _timerptr->start( 500 );
	    
	    //------------------------------------------------------------------------------
        // clear stored images
        //------------------------------------------------------------------------------
        QString path = "../../svg/";
        QDir dir( path );
        dir.setNameFilters( QStringList() << "*.*" );
        dir.setFilter( QDir::Files );
        for( const QString &dirFile: dir.entryList() ) {
            dir.remove( dirFile );
        }

        //------------------------------------------------------------------------------
        // configuration file
        //------------------------------------------------------------------------------
        string configFilePath = qApp->applicationDirPath().toStdString() + "/../config/MainWindow.conf";
        KeiRo::Base::Config conf( configFilePath );

        int icon_width = 0,
            icon_height = 0;

        if ( conf.has( "mainwidget_width" ) ){
            string parammainwidgetWidth = conf.gets( "mainwidget_width" );
            KeiRo::Base::Common::setMainwidgetWidth( stoi( parammainwidgetWidth ) );
        }
        if ( conf.has( "mainwidget_height" ) ){
            string parammainwidgetHeight = conf.gets( "mainwidget_height" );
	        KeiRo::Base::Common::setMainwidgetHeight( stoi( parammainwidgetHeight ) );
        }
        if ( conf.has( "dockwidget_width" ) ){
            string paramDockWidgetWidth = conf.gets( "dockwidget_width" );
	        KeiRo::Base::Common::setDockWidgetWidth( stoi( paramDockWidgetWidth ) );
       }
        if ( conf.has( "menubar_height" ) ){
            string paramMenuBarHeight = conf.gets( "menubar_height" );
	        KeiRo::Base::Common::setMenubarHeight( stoi( paramMenuBarHeight ) );
        }
        if ( conf.has( "icon_width" ) ){
            string paramIconWidth = conf.gets( "icon_width" );
            icon_width = stoi( paramIconWidth );
        }
        if ( conf.has( "icon_height" ) ){
            string paramIconHeight = conf.gets( "icon_height" );
            icon_height = stoi( paramIconHeight );
        }

        setGeometry( QRect( 50, 50,
							KeiRo::Base::Common::getMainwidgetWidth()+KeiRo::Base::Common::getDockWidgetWidth(),
							KeiRo::Base::Common::getMainwidgetHeight() + KeiRo::Base::Common::getMenubarHeight() ) );
	    setMinimumSize(QSize( KeiRo::Base::Common::getMainwidgetWidth()+KeiRo::Base::Common::getDockWidgetWidth(),
						   KeiRo::Base::Common::getMainwidgetHeight() + KeiRo::Base::Common::getMenubarHeight()
						   + icon_height ) );
	    
#ifdef DEBUG
        cerr << "mainwidget_width = " << KeiRo::Base::Common::getMainwidgetWidth() << endl;
        cerr << "mainwidget_height = " << KeiRo::Base::Common::getMainwidgetHeight() << endl;
        cerr << "dockwidget_width = " << KeiRo::Base::Common::getDockWidgetWidth() << endl;
        cerr << "menubar_height = " << KeiRo::Base::Common::getMenubarHeight() << endl;
        cerr << "icon_width = " << icon_width << endl;
        cerr << "icon_height = " << icon_height << endl;
	    cerr << "win_width = " << width() << " win_height = " << height() << endl;
#endif // DEBUG
    }
    

    //------------------------------------------------------------------------------
    //	Event handlers
    //------------------------------------------------------------------------------

    //------------------------------------------------------------------------------
    //	Special functions
    //------------------------------------------------------------------------------
    //
    //  MainWindow::newFile -- open new file
    //
    //  Inputs
    //  none
    //
    //  Outputs
    //  none
    //
    void MainWindow::newFile( void )
    {
        _mainGV->simulateKey( Qt::Key_L );
    }
	
	//
	//  MainWindow::exportPNG -- export main window as png
	//
	//  Inputs
	//  none
	//
	//  Outputs
	//  none
	//
	void MainWindow::exportPNG( void )
	{
    	double ww = KeiRo::Base::Common::getMainwidgetWidth();
		double wh = KeiRo::Base::Common::getMainwidgetHeight();

    	_mainGV->exportPNG( -0.5*ww, -0.5*wh, ww, wh );
	}
	
    //
    //  MainWindow::print -- print
    //
    //  Inputs
    //  none
    //
    //  Outputs
    //  none
    //
    void MainWindow::print( void )
    {
    }

    //
    //  MainWindow::undo -- undo
    //
    //  Inputs
    //  none
    //
    //  Outputs
    //  none
    //
    void MainWindow::undo( void )
    {
    }

    //
    //  MainWindow::save -- save
    //
    //  Inputs
    //  none
    //
    //  Outputs
    //  none
    //
    void MainWindow::save( void )
    {
    #ifdef REVISE
        QMimeDatabase mimeDatabase;
        QString fileName = QFileDialog::getSaveFileName(this,
                            tr("Choose a file name"), ".",
                            mimeDatabase.mimeTypeForName("text/html").filterString());
        if (fileName.isEmpty())
            return;
        QFile file(fileName);
        if (!file.open(QFile::WriteOnly | QFile::Text)) {
            QMessageBox::warning(this, tr("Dock Widgets"),
                                 tr("Cannot write file %1:\n%2.")
                                 .arg(QDir::toNativeSeparators(fileName), file.errorString()));
            return;
        }

        QTextStream out(&file);
        QApplication::setOverrideCursor(Qt::WaitCursor);
        out << textEdit->toHtml();
        QApplication::restoreOverrideCursor();

        statusBar()->showMessage(tr("Saved '%1'").arg(fileName), 2000);
    #endif // REVISE
    }

    //
    //  MainWindow::about -- about
    //
    //  Inputs
    //  none
    //
    //  Outputs
    //  none
    //
    void MainWindow::about( void )
    {
       QMessageBox::about(this, tr("About KeiRo"),
                tr( "Map-based biological pathway diagram"));
    }
	
} // namespace Ui