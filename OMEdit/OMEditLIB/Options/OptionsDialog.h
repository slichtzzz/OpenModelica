/*
 * This file is part of OpenModelica.
 *
 * Copyright (c) 1998-CurrentYear, Open Source Modelica Consortium (OSMC),
 * c/o Linköpings universitet, Department of Computer and Information Science,
 * SE-58183 Linköping, Sweden.
 *
 * All rights reserved.
 *
 * THIS PROGRAM IS PROVIDED UNDER THE TERMS OF GPL VERSION 3 LICENSE OR
 * THIS OSMC PUBLIC LICENSE (OSMC-PL) VERSION 1.2.
 * ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS PROGRAM CONSTITUTES
 * RECIPIENT'S ACCEPTANCE OF THE OSMC PUBLIC LICENSE OR THE GPL VERSION 3,
 * ACCORDING TO RECIPIENTS CHOICE.
 *
 * The OpenModelica software and the Open Source Modelica
 * Consortium (OSMC) Public License (OSMC-PL) are obtained
 * from OSMC, either from the above address,
 * from the URLs: http://www.ida.liu.se/projects/OpenModelica or
 * http://www.openmodelica.org, and in the OpenModelica distribution.
 * GNU version 3 is obtained from: http://www.gnu.org/copyleft/gpl.html.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without
 * even the implied warranty of  MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE, EXCEPT AS EXPRESSLY SET FORTH
 * IN THE BY RECIPIENT SELECTED SUBSIDIARY LICENSE CONDITIONS OF OSMC-PL.
 *
 * See the full OSMC Public License conditions for more details.
 *
 */
/*
 * @author Adeel Asghar <adeel.asghar@liu.se>
 */

#ifndef OPTIONSDIALOG_H
#define OPTIONSDIALOG_H

#include "Util/Helper.h"
#include "Util/Utilities.h"
#include "Util/StringHandler.h"

#include <QFontComboBox>
#include <QStackedWidget>
#include <QDialogButtonBox>
#include <QRadioButton>
#include <QTreeWidget>
#include <QDialog>
#include <QLineEdit>

class GeneralSettingsPage;
class LibrariesPage;
class TextEditorPage;
class ModelicaEditorPage;
class MetaModelicaEditorPage;
class CompositeModelEditorPage;
class OMSimulatorEditorPage;
class CEditorPage;
class HTMLEditorPage;
class GraphicalViewsPage;
class SimulationPage;
class MessagesPage;
class NotificationsPage;
class LineStylePage;
class FillStylePage;
class PlottingPage;
class FigaroPage;
class DebuggerPage;
class FMIPage;
class TLMPage;
class OMSimulatorPage;
class TraceabilityPage;
class TabSettings;
class StackFramesWidget;
class TranslationFlagsWidget;
class LibraryTreeItem;

class OptionsDialog : public QDialog
{
  Q_OBJECT
private:
  // the only class that is allowed to create and destroy
  friend class MainWindow;

  static void create();
  static void destroy();
  OptionsDialog(QWidget *pParent = 0);

  static OptionsDialog *mpInstance;
public:
  static OptionsDialog* instance() {
    create();
    return mpInstance;
  }
  ~OptionsDialog() { mpInstance = nullptr; }
  void readSettings();
  void readGeneralSettings();
  void readLibrariesSettings();
  void readTextEditorSettings();
  void readModelicaEditorSettings();
  void readMetaModelicaEditorSettings();
  void readCompositeModelEditorSettings();
  void readOMSimulatorEditorSettings();
  void readCEditorSettings();
  void readHTMLEditorSettings();
  void readGraphicalViewsSettings();
  void readSimulationSettings();
  void readMessagesSettings();
  void readNotificationsSettings();
  void readLineStyleSettings();
  void readFillStyleSettings();
  void readPlottingSettings();
  void readFigaroSettings();
  void readDebuggerSettings();
  void readFMISettings();
  void readTLMSettings();
  void readOMSimulatorSettings();
  void readTraceabilitySettings();
  void saveGeneralSettings();
  void saveNFAPISettings();
  void saveLibrariesSettings();
  void saveTextEditorSettings();
  void saveModelicaEditorSettings();
  void saveMetaModelicaEditorSettings();
  void saveCompositeModelEditorSettings();
  void saveOMSimulatorEditorSettings();
  void saveCEditorSettings();
  void saveHTMLEditorSettings();
  void saveTLMSettings();
  void saveOMSimulatorSettings();
  void saveTraceabilitySettings();
  void saveGraphicalViewsSettings();
  void saveSimulationSettings();
  void saveGlobalSimulationSettings();
  void saveMessagesSettings();
  void saveNotificationsSettings();
  void saveLineStyleSettings();
  void saveFillStyleSettings();
  void savePlottingSettings();
  void saveFigaroSettings();
  void saveDebuggerSettings();
  void saveFMISettings();
  void setUpDialog();
  void addListItems();
  void createPages();
  void addPage(QWidget* pPage);
  GeneralSettingsPage* getGeneralSettingsPage() {return mpGeneralSettingsPage;}
  LibrariesPage* getLibrariesPage() {return mpLibrariesPage;}
  TextEditorPage* getTextEditorPage() {return mpTextEditorPage;}
  ModelicaEditorPage* getModelicaEditorPage() {return mpModelicaEditorPage;}
  MetaModelicaEditorPage* getMetaModelicaEditorPage() {return mpMetaModelicaEditorPage;}
  CompositeModelEditorPage* getCompositeModelEditorPage() {return mpCompositeModelEditorPage;}
  OMSimulatorEditorPage* getOMSimulatorEditorPage() {return mpOMSimulatorEditorPage;}
  CEditorPage* getCEditorPage() {return mpCEditorPage;}
  HTMLEditorPage* getHTMLEditorPage() {return mpHTMLEditorPage;}
  GraphicalViewsPage* getGraphicalViewsPage() {return mpGraphicalViewsPage;}
  SimulationPage* getSimulationPage() {return mpSimulationPage;}
  MessagesPage* getMessagesPage() {return mpMessagesPage;}
  NotificationsPage* getNotificationsPage() {return mpNotificationsPage;}
  LineStylePage* getLineStylePage() {return mpLineStylePage;}
  FillStylePage* getFillStylePage() {return mpFillStylePage;}
  PlottingPage* getPlottingPage() {return mpPlottingPage;}
  FigaroPage* getFigaroPage() {return mpFigaroPage;}
  DebuggerPage* getDebuggerPage() {return mpDebuggerPage;}
  FMIPage* getFMIPage() {return mpFMIPage;}
  TLMPage* getTLMPage() {return mpTLMPage;}
  OMSimulatorPage* getOMSimulatorPage() {return mpOMSimulatorPage;}
  TraceabilityPage* getTraceabilityPage() {return mpTraceabilityPage;}
  void emitModelicaEditorSettingsChanged() {emit modelicaEditorSettingsChanged();}
  void saveDialogGeometry();
  void show();
  TabSettings getTabSettings();
  virtual bool eventFilter(QObject *pObject, QEvent *pEvent) override;
signals:
  void textSettingsChanged();
  void modelicaEditorSettingsChanged();
  void metaModelicaEditorSettingsChanged();
  void compositeModelEditorSettingsChanged();
  void omsimulatorEditorSettingsChanged();
  void cEditorSettingsChanged();
  void HTMLEditorSettingsChanged();
public slots:
  void changePage(QListWidgetItem *current, QListWidgetItem *previous);
  void reject() override;
  void saveSettings();
  void reset();
private:
  bool mDetectChange;
  GeneralSettingsPage *mpGeneralSettingsPage;
  LibrariesPage *mpLibrariesPage;
  TextEditorPage *mpTextEditorPage;
  ModelicaEditorPage *mpModelicaEditorPage;
  MetaModelicaEditorPage *mpMetaModelicaEditorPage;
  CompositeModelEditorPage *mpCompositeModelEditorPage;
  OMSimulatorEditorPage *mpOMSimulatorEditorPage;
  CEditorPage *mpCEditorPage;
  HTMLEditorPage *mpHTMLEditorPage;
  GraphicalViewsPage *mpGraphicalViewsPage;
  SimulationPage *mpSimulationPage;
  QString mMatchingAlgorithm;
  QString mIndexReductionMethod;
  bool mInitialization;
  bool mEvaluateAllParameters;
  bool mNLSanalyticJacobian;
  bool mParmodauto;
  bool mOldInstantiation;
  bool mEnableFMUImport;
  QString mAdditionalTranslationFlags;
  MessagesPage *mpMessagesPage;
  NotificationsPage *mpNotificationsPage;
  LineStylePage *mpLineStylePage;
  FillStylePage *mpFillStylePage;
  PlottingPage *mpPlottingPage;
  FigaroPage *mpFigaroPage;
  DebuggerPage *mpDebuggerPage;
  FMIPage *mpFMIPage;
  TLMPage *mpTLMPage;
  OMSimulatorPage *mpOMSimulatorPage;
  TraceabilityPage *mpTraceabilityPage;
  QSettings *mpSettings;
  QListWidget *mpOptionsList;
  QStackedWidget *mpPagesWidget;
  Label *mpChangesEffectLabel;
  QPushButton *mpCancelButton;
  QPushButton *mpOkButton;
  QPushButton *mpResetButton;
  QDialogButtonBox *mpButtonBox;
};

class CodeColorsWidget : public QWidget
{
  Q_OBJECT
public:
  CodeColorsWidget(QWidget *pParent = 0);
  QListWidget* getItemsListWidget() {return mpItemsListWidget;}
  PreviewPlainTextEdit* getPreviewPlainTextEdit() {return mpPreviewPlainTextEdit;}
private:
  QGroupBox *mpColorsGroupBox;
  Label *mpItemsLabel;
  QListWidget *mpItemsListWidget;
  Label *mpItemColorLabel;
  QPushButton *mpItemColorPickButton;
  Label *mpPreviewLabel;
  PreviewPlainTextEdit *mpPreviewPlainTextEdit;
  ListWidgetItem *mpTextItem;
  ListWidgetItem *mpNumberItem;
  ListWidgetItem *mpKeywordItem;
  ListWidgetItem *mpTypeItem;
  ListWidgetItem *mpFunctionItem;
  ListWidgetItem *mpQuotesItem;
  ListWidgetItem *mpCommentItem;
signals:
  void colorUpdated();
private slots:
  void pickColor();
};

class GeneralSettingsPage : public QWidget
{
  Q_OBJECT
public:
  enum AccessAnnotations {
    Always = 0,
    Loading = 1,
    Never = 2
  };
  GeneralSettingsPage(OptionsDialog *pOptionsDialog);
  QComboBox* getLanguageComboBox() {return mpLanguageComboBox;}
  void setWorkingDirectory(QString value) {mpWorkingDirectoryTextBox->setText(value);}
  QString getWorkingDirectory();
  QSpinBox* getToolbarIconSizeSpinBox() {return mpToolbarIconSizeSpinBox;}
  void setPreserveUserCustomizations(bool value) {mpPreserveUserCustomizations->setChecked(value);}
  bool getPreserveUserCustomizations() {return mpPreserveUserCustomizations->isChecked();}
  void setTerminalCommand(QString value) {mpTerminalCommandTextBox->setText(value);}
  QString getTerminalCommand() {return mpTerminalCommandTextBox->text();}
  void setTerminalCommandArguments(QString value) {mpTerminalCommandArgumentsTextBox->setText(value);}
  QString getTerminalCommandArguments() {return mpTerminalCommandArgumentsTextBox->text();}
  QCheckBox* getHideVariablesBrowserCheckBox() {return mpHideVariablesBrowserCheckBox;}
  QComboBox* getActivateAccessAnnotationsComboBox() {return mpActivateAccessAnnotationsComboBox;}
  QCheckBox* getCreateBackupFileCheckbox() {return mpCreateBackupFileCheckbox;}
  QCheckBox* getDisplayNFAPIErrorsWarningsCheckBox() {return mpDisplayNFAPIErrorsWarningsCheckBox;}
  QSpinBox* getLibraryIconSizeSpinBox() {return mpLibraryIconSizeSpinBox;}
  QSpinBox* getLibraryIconTextLengthSpinBox() {return mpLibraryIconTextLengthSpinBox;}
  void setShowProtectedClasses(bool value) {mpShowProtectedClasses->setChecked(value);}
  bool getShowProtectedClasses() {return mpShowProtectedClasses->isChecked();}
  void setShowHiddenClasses(bool value) {mpShowHiddenClasses->setChecked(value);}
  bool getShowHiddenClasses() {return mpShowHiddenClasses->isChecked();}
  QCheckBox* getSynchronizeWithModelWidgetCheckBox() {return mpSynchronizeWithModelWidgetCheckBox;}
  QGroupBox* getEnableAutoSaveGroupBox() {return mpEnableAutoSaveGroupBox;}
  QSpinBox* getAutoSaveIntervalSpinBox() {return mpAutoSaveIntervalSpinBox;}
  int getWelcomePageView();
  void setWelcomePageView(int view);
  QCheckBox* getShowLatestNewsCheckBox() {return mpShowLatestNewsCheckBox;}
  QSpinBox* getRecentFilesAndLatestNewsSizeSpinBox() {return mpRecentFilesAndLatestNewsSizeSpinBox;}
  QCheckBox* getDisableInstanceAPICheckBox() {return mpDisableInstanceAPICheckBox;}
private:
  OptionsDialog *mpOptionsDialog;
  QGroupBox *mpGeneralSettingsGroupBox;
  Label *mpLanguageLabel;
  QComboBox *mpLanguageComboBox;
  Label *mpWorkingDirectoryLabel;
  QLineEdit *mpWorkingDirectoryTextBox;
  QPushButton *mpWorkingDirectoryBrowseButton;
  Label *mpToolbarIconSizeLabel;
  QSpinBox *mpToolbarIconSizeSpinBox;
  QCheckBox *mpPreserveUserCustomizations;
  Label *mpTerminalCommandLabel;
  QLineEdit *mpTerminalCommandTextBox;
  QPushButton *mpTerminalCommandBrowseButton;
  Label *mpTerminalCommandArgumentsLabel;
  QLineEdit *mpTerminalCommandArgumentsTextBox;
  QCheckBox *mpHideVariablesBrowserCheckBox;
  Label *mpActivateAccessAnnotationsLabel;
  QComboBox *mpActivateAccessAnnotationsComboBox;
  QCheckBox *mpCreateBackupFileCheckbox;
  QCheckBox *mpDisplayNFAPIErrorsWarningsCheckBox;
  QGroupBox *mpLibraryBrowserGroupBox;
  Label *mpLibraryIconSizeLabel;
  QSpinBox *mpLibraryIconSizeSpinBox;
  Label *mpLibraryIconTextLengthLabel;
  QSpinBox *mpLibraryIconTextLengthSpinBox;
  QCheckBox *mpShowProtectedClasses;
  QCheckBox *mpShowHiddenClasses;
  QCheckBox *mpSynchronizeWithModelWidgetCheckBox;
  QGroupBox *mpEnableAutoSaveGroupBox;
  Label *mpAutoSaveIntervalLabel;
  QSpinBox *mpAutoSaveIntervalSpinBox;
  Label *mpAutoSaveSecondsLabel;
  QGroupBox *mpWelcomePageGroupBox;
  QRadioButton *mpHorizontalViewRadioButton;
  QRadioButton *mpVerticalViewRadioButton;
  QCheckBox *mpShowLatestNewsCheckBox;
  QSpinBox *mpRecentFilesAndLatestNewsSizeSpinBox;
  QGroupBox *mpOptionalFeaturesGroupBox;
  QCheckBox *mpDisableInstanceAPICheckBox;
public slots:
  void selectWorkingDirectory();
  void selectTerminalCommand();
  void autoSaveIntervalValueChanged(int value);
};

class LibrariesPage : public QWidget
{
  Q_OBJECT
public:
  LibrariesPage(OptionsDialog *pOptionsDialog);
  QLineEdit *getModelicaPathTextBox() const {return mpModelicaPathTextBox;}
  QCheckBox *getLoadLatestModelicaCheckbox() const {return mpLoadLatestModelicaCheckbox;}
  QTreeWidget* getSystemLibrariesTree() {return mpSystemLibrariesTree;}
  QTreeWidget* getUserLibrariesTree() {return mpUserLibrariesTree;}
  OptionsDialog *mpOptionsDialog;
private:
  QGroupBox *mpSystemLibrariesGroupBox;
  Label *mpModelicaPathLabel;
  QLineEdit *mpModelicaPathTextBox;
  QPushButton *mpModelicaPathBrowseButton;
  Label *mpSystemLibrariesNoteLabel;
  QCheckBox *mpLoadLatestModelicaCheckbox;
  QTreeWidget *mpSystemLibrariesTree;
  QPushButton *mpAddSystemLibraryButton;
  QPushButton *mpRemoveSystemLibraryButton;
  QPushButton *mpEditSystemLibraryButton;
  QDialogButtonBox *mpSystemLibrariesButtonBox;
  QGroupBox *mpUserLibrariesGroupBox;
  QTreeWidget *mpUserLibrariesTree;
  QPushButton *mpAddUserLibraryButton;
  QPushButton *mpRemoveUserLibraryButton;
  QPushButton *mpEditUserLibraryButton;
  QDialogButtonBox *mpUserLibrariesButtonBox;
private slots:
  void selectModelicaPath();
  void openAddSystemLibrary();
  void removeSystemLibrary();
  void openEditSystemLibrary();
  void openAddUserLibrary();
  void removeUserLibrary();
  void openEditUserLibrary();
};

class AddSystemLibraryDialog : public QDialog
{
  Q_OBJECT
public:
  AddSystemLibraryDialog(LibrariesPage *pLibrariesPage, bool editFlag = false);
  bool nameExists(QTreeWidgetItem *pItem = 0);
  QComboBox *getNameComboBox() const {return mpNameComboBox;}
  QComboBox *getVersionsComboBox() const {return mpVersionsComboBox;}
private:
  LibrariesPage *mpLibrariesPage;
  Label *mpNameLabel;
  QComboBox *mpNameComboBox;
  Label *mpValueLabel;
  QComboBox *mpVersionsComboBox;
  QPushButton *mpOkButton;
  QPushButton *mpCancelButton;
  QPushButton *mpInstallLibraryButton;
  QDialogButtonBox *mpButtonBox;
  bool mEditFlag;

  void getSystemLibraries();
private slots:
  void getLibraryVersions(const QString &library);
  void addSystemLibrary();
  void openInstallLibraryDialog();
};

class AddUserLibraryDialog : public QDialog
{
  Q_OBJECT
public:
  AddUserLibraryDialog(LibrariesPage *pLibrariesPage);
  bool pathExists(QTreeWidgetItem *pItem = 0);

  LibrariesPage *mpLibrariesPage;
  Label *mpPathLabel;
  QLineEdit *mpPathTextBox;
  QPushButton *mpPathBrowseButton;
  Label *mpEncodingLabel;
  QComboBox *mpEncodingComboBox;
  QPushButton *mpOkButton;
  QPushButton *mpCancelButton;
  QDialogButtonBox *mpButtonBox;
  bool mEditFlag;
private slots:
  void browseUserLibraryPath();
  void addUserLibrary();
};

class TextEditorPage : public QWidget
{
  Q_OBJECT
public:
  TextEditorPage(OptionsDialog *pOptionsDialog);
  QComboBox *getLineEndingComboBox() {return mpLineEndingComboBox;}
  QComboBox *getBOMComboBox() {return mpBOMComboBox;}
  QComboBox *getTabPolicyComboBox() {return mpTabPolicyComboBox;}
  QSpinBox *getTabSizeSpinBox() {return mpTabSizeSpinBox;}
  QSpinBox *getIndentSpinBox() {return mpIndentSpinBox;}
  QGroupBox* getSyntaxHighlightingGroupBox() {return mpSyntaxHighlightingGroupBox;}
  QCheckBox* getAutoCompleteCheckBox() {return mpAutoCompleteCheckBox;}
  QCheckBox* getCodeFoldingCheckBox() {return mpCodeFoldingCheckBox;}
  QCheckBox* getMatchParenthesesCommentsQuotesCheckBox() {return mpMatchParenthesesCommentsQuotesCheckBox;}
  QCheckBox* getLineWrappingCheckbox() {return mpLineWrappingCheckbox;}
  QFontComboBox* getFontFamilyComboBox() {return mpFontFamilyComboBox;}
  DoubleSpinBox* getFontSizeSpinBox() {return mpFontSizeSpinBox;}
private:
  OptionsDialog *mpOptionsDialog;
  QGroupBox *mpFormatGroupBox;
  Label *mpLineEndingLabel;
  QComboBox *mpLineEndingComboBox;
  Label *mpBOMLabel;
  QComboBox *mpBOMComboBox;
  QGroupBox *mpTabsAndIndentation;
  Label *mpTabPolicyLabel;
  QComboBox *mpTabPolicyComboBox;
  Label *mpTabSizeLabel;
  QSpinBox *mpTabSizeSpinBox;
  Label *mpIndentSizeLabel;
  QSpinBox *mpIndentSpinBox;
  QGroupBox *mpSyntaxHighlightAndTextWrappingGroupBox;
  QGroupBox *mpSyntaxHighlightingGroupBox;
  QGroupBox *mpAutoCompleteGroupBox;
  QCheckBox *mpAutoCompleteCheckBox;
  QCheckBox *mpCodeFoldingCheckBox;
  QCheckBox *mpMatchParenthesesCommentsQuotesCheckBox;
  QCheckBox *mpLineWrappingCheckbox;
  QGroupBox *mpFontGroupBox;
  Label *mpFontFamilyLabel;
  QFontComboBox *mpFontFamilyComboBox;
  Label *mpFontSizeLabel;
  DoubleSpinBox *mpFontSizeSpinBox;
};

class ModelicaEditorPage : public QWidget
{
  Q_OBJECT
public:
  ModelicaEditorPage(OptionsDialog *pOptionsDialog);
  OptionsDialog* getOptionsDialog() {return mpOptionsDialog;}
  QCheckBox *getPreserveTextIndentationCheckBox() {return mpPreserveTextIndentationCheckBox;}
  void setColor(QString item, QColor color);
  QColor getColor(QString item);
  void emitUpdatePreview() {emit updatePreview();}
private:
  OptionsDialog *mpOptionsDialog;
  QCheckBox *mpPreserveTextIndentationCheckBox;
  CodeColorsWidget *mpCodeColorsWidget;
signals:
  void updatePreview();
public slots:
  void setLineWrapping(bool enabled);
};

class MetaModelicaEditorPage : public QWidget
{
  Q_OBJECT
public:
  MetaModelicaEditorPage(OptionsDialog *pOptionsDialog);
  OptionsDialog* getOptionsDialog() {return mpOptionsDialog;}
  void setColor(QString item, QColor color);
  QColor getColor(QString item);
  void emitUpdatePreview() {emit updatePreview();}
private:
  OptionsDialog *mpOptionsDialog;
  CodeColorsWidget *mpCodeColorsWidget;
signals:
  void updatePreview();
public slots:
  void setLineWrapping(bool enabled);
};

class CompositeModelEditorPage : public QWidget
{
  Q_OBJECT
public:
  CompositeModelEditorPage(OptionsDialog *pOptionsDialog);
  OptionsDialog* getOptionsDialog() {return mpOptionsDialog;}
  void setColor(QString item, QColor color);
  QColor getColor(QString item);
  void emitUpdatePreview() {emit updatePreview();}
private:
  OptionsDialog *mpOptionsDialog;
  CodeColorsWidget *mpCodeColorsWidget;
signals:
  void updatePreview();
public slots:
  void setLineWrapping(bool enabled);
};

class OMSimulatorEditorPage : public QWidget
{
  Q_OBJECT
public:
  OMSimulatorEditorPage(OptionsDialog *pOptionsDialog);
  OptionsDialog* getOptionsDialog() {return mpOptionsDialog;}
  void setColor(QString item, QColor color);
  QColor getColor(QString item);
  void emitUpdatePreview() {emit updatePreview();}
private:
  OptionsDialog *mpOptionsDialog;
  CodeColorsWidget *mpCodeColorsWidget;
signals:
  void updatePreview();
public slots:
  void setLineWrapping(bool enabled);
};

class CEditorPage : public QWidget
{
  Q_OBJECT
public:
  CEditorPage(OptionsDialog *pOptionsDialog);
  OptionsDialog* getOptionsDialog() {return mpOptionsDialog;}
  void setColor(QString item, QColor color);
  QColor getColor(QString item);
  void emitUpdatePreview() {emit updatePreview();}
private:
  OptionsDialog *mpOptionsDialog;
  CodeColorsWidget *mpCodeColorsWidget;
signals:
  void updatePreview();
public slots:
  void setLineWrapping(bool enabled);
};

class HTMLEditorPage : public QWidget
{
  Q_OBJECT
public:
  HTMLEditorPage(OptionsDialog *pOptionsDialog);
  OptionsDialog* getOptionsDialog() {return mpOptionsDialog;}
  void setColor(QString item, QColor color);
  QColor getColor(QString item);
  void emitUpdatePreview() {emit updatePreview();}
private:
  OptionsDialog *mpOptionsDialog;
  CodeColorsWidget *mpCodeColorsWidget;
signals:
  void updatePreview();
public slots:
  void setLineWrapping(bool enabled);
};

class GraphicalViewsPage : public QWidget
{
  Q_OBJECT
public:
  GraphicalViewsPage(OptionsDialog *pOptionsDialog);
  void setModelingViewMode(QString value);
  QString getModelingViewMode();
  void setDefaultView(QString value);
  QString getDefaultView();
  QCheckBox *getMoveConnectorsTogetherCheckBox() const {return mpMoveConnectorsTogetherCheckBox;}
  void setIconViewExtentLeft(double extentLeft);
  double getIconViewExtentLeft();
  void setIconViewExtentBottom(double extentBottom);
  double getIconViewExtentBottom();
  void setIconViewExtentRight(double extentRight);
  double getIconViewExtentRight();
  void setIconViewExtentTop(double extentTop);
  double getIconViewExtentTop();
  void setIconViewGridHorizontal(double gridHorizontal);
  double getIconViewGridHorizontal();
  void setIconViewGridVertical(double gridVertical);
  double getIconViewGridVertical();
  void setIconViewScaleFactor(double scaleFactor);
  double getIconViewScaleFactor();
  void setIconViewPreserveAspectRation(bool preserveAspectRation);
  bool getIconViewPreserveAspectRation();
  void setDiagramViewExtentLeft(double extentLeft);
  double getDiagramViewExtentLeft();
  void setDiagramViewExtentBottom(double extentBottom);
  double getDiagramViewExtentBottom();
  void setDiagramViewExtentRight(double extentRight);
  double getDiagramViewExtentRight();
  void setDiagramViewExtentTop(double extentTop);
  double getDiagramViewExtentTop();
  void setDiagramViewGridHorizontal(double gridHorizontal);
  double getDiagramViewGridHorizontal();
  void setDiagramViewGridVertical(double gridVertical);
  double getDiagramViewGridVertical();
  void setDiagramViewScaleFactor(double scaleFactor);
  double getDiagramViewScaleFactor();
  void setDiagramViewPreserveAspectRation(bool preserveAspectRation);
  bool getDiagramViewPreserveAspectRation();
private:
  OptionsDialog *mpOptionsDialog;
  QRadioButton *mpModelingTabbedViewRadioButton;
  QRadioButton *mpModelingSubWindowViewRadioButton;
  QRadioButton *mpIconViewRadioButton;
  QRadioButton *mpDiagramViewRadioButton;
  QRadioButton *mpTextViewRadioButton;
  QRadioButton *mpDocumentationViewRadioButton;
  QCheckBox *mpMoveConnectorsTogetherCheckBox;
  DoubleSpinBox *mpIconViewLeftSpinBox;
  DoubleSpinBox *mpIconViewBottomSpinBox;
  DoubleSpinBox *mpIconViewRightSpinBox;
  DoubleSpinBox *mpIconViewTopSpinBox;
  DoubleSpinBox *mpIconViewGridHorizontalSpinBox;
  DoubleSpinBox *mpIconViewGridVerticalSpinBox;
  DoubleSpinBox *mpIconViewScaleFactorSpinBox;
  QCheckBox *mpIconViewPreserveAspectRatioCheckBox;
  DoubleSpinBox *mpDiagramViewLeftSpinBox;
  DoubleSpinBox *mpDiagramViewBottomSpinBox;
  DoubleSpinBox *mpDiagramViewRightSpinBox;
  DoubleSpinBox *mpDiagramViewTopSpinBox;
  DoubleSpinBox *mpDiagramViewGridHorizontalSpinBox;
  DoubleSpinBox *mpDiagramViewGridVerticalSpinBox;
  DoubleSpinBox *mpDiagramViewScaleFactorSpinBox;
  QCheckBox *mpDiagramViewPreserveAspectRatioCheckBox;
};

class SimulationPage : public QWidget
{
  Q_OBJECT
public:
  SimulationPage(OptionsDialog *pOptionsDialog);
  TranslationFlagsWidget *getTranslationFlagsWidget() const {return mpTranslationFlagsWidget;}
  QComboBox* getTargetLanguageComboBox() {return mpTargetLanguageComboBox;}
  QComboBox* getTargetBuildComboBox() {return mpTargetBuildComboBox;}
  QComboBox* getCompilerComboBox() {return mpCompilerComboBox;}
  QComboBox* getCXXCompilerComboBox() {return mpCXXCompilerComboBox;}
#ifdef Q_OS_WIN
  QCheckBox* getUseStaticLinkingCheckBox() {return mpUseStaticLinkingCheckBox;}
#endif
  void setPostCompilationCommand(const QString & cmd) {mpPostCompilationCommandLineEdit->setText(cmd);}
  QString getPostCompilationCommand() {return mpPostCompilationCommandLineEdit->text().trimmed();}
  QCheckBox* getIgnoreCommandLineOptionsAnnotationCheckBox() {return mpIgnoreCommandLineOptionsAnnotationCheckBox;}
  QCheckBox* getIgnoreSimulationFlagsAnnotationCheckBox() {return mpIgnoreSimulationFlagsAnnotationCheckBox;}
  QCheckBox* getSaveClassBeforeSimulationCheckBox() {return mpSaveClassBeforeSimulationCheckBox;}
  QCheckBox* getSwitchToPlottingPerspectiveCheckBox() {return mpSwitchToPlottingPerspectiveCheckBox;}
  QCheckBox* getCloseSimulationOutputWidgetsBeforeSimulationCheckBox() {return mpCloseSimulationOutputWidgetsBeforeSimulationCheckBox;}
  QCheckBox* getDeleteIntermediateCompilationFilesCheckBox() {return mpDeleteIntermediateCompilationFilesCheckBox;}
  QCheckBox* getDeleteEntireSimulationDirectoryCheckBox() {return mpDeleteEntireSimulationDirectoryCheckBox;}
  void setOutputMode(QString value);
  QString getOutputMode();
  QSpinBox* getDisplayLimitSpinBox() {return mpDisplayLimitSpinBox;}
private:
  OptionsDialog *mpOptionsDialog;
  QGroupBox *mpSimulationGroupBox;
  QGroupBox *mpTranslationFlagsGroupBox;
  TranslationFlagsWidget *mpTranslationFlagsWidget;
  Label *mpTargetLanguageLabel;
  QComboBox *mpTargetLanguageComboBox;
  Label *mpTargetBuildLabel;
  QComboBox *mpTargetBuildComboBox;
  Label *mpCompilerLabel;
  QComboBox *mpCompilerComboBox;
  Label *mpCXXCompilerLabel;
  QComboBox *mpCXXCompilerComboBox;
#ifdef Q_OS_WIN
  QCheckBox *mpUseStaticLinkingCheckBox;
#endif
  QLineEdit *mpPostCompilationCommandLineEdit;
  QCheckBox *mpIgnoreCommandLineOptionsAnnotationCheckBox;
  QCheckBox *mpIgnoreSimulationFlagsAnnotationCheckBox;
  QCheckBox *mpSaveClassBeforeSimulationCheckBox;
  QCheckBox *mpSwitchToPlottingPerspectiveCheckBox;
  QCheckBox *mpCloseSimulationOutputWidgetsBeforeSimulationCheckBox;
  QCheckBox *mpDeleteIntermediateCompilationFilesCheckBox;
  QCheckBox *mpDeleteEntireSimulationDirectoryCheckBox;
  QGroupBox *mpOutputGroupBox;
  QRadioButton *mpStructuredRadioButton;
  QRadioButton *mpFormattedTextRadioButton;
  Label *mpDisplayLimitLabel;
  QSpinBox *mpDisplayLimitSpinBox;
  Label *mpDisplayLimitMBLabel;
public slots:
  void targetBuildChanged(int index);
  void displayLimitValueChanged(int value);
};

class MessagesPage : public QWidget
{
  Q_OBJECT
public:
  MessagesPage(OptionsDialog *pOptionsDialog);
  QSpinBox* getOutputSizeSpinBox() {return mpOutputSizeSpinBox;}
  QCheckBox* getResetMessagesNumberBeforeSimulationCheckBox() {return mpResetMessagesNumberBeforeSimulationCheckBox;}
  QCheckBox* getClearMessagesBrowserBeforeSimulationCheckBox() {return mpClearMessagesBrowserBeforeSimulationCheckBox;}
  QFontComboBox* getFontFamilyComboBox() {return mpFontFamilyComboBox;}
  DoubleSpinBox* getFontSizeSpinBox() {return mpFontSizeSpinBox;}
  void setNotificationColor(QColor color) {mNotificaitonColor = color;}
  QColor getNotificationColor() const {return mNotificaitonColor;}
  void setNotificationPickColorButtonIcon();
  void setWarningColor(QColor color) {mWarningColor = color;}
  QColor getWarningColor() const {return mWarningColor;}
  void setWarningPickColorButtonIcon();
  void setErrorColor(QColor color) {mErrorColor = color;}
  QColor getErrorColor() const {return mErrorColor;}
  void setErrorPickColorButtonIcon();
  QColor getColor(const StringHandler::SimulationMessageType type) const;
private:
  OptionsDialog *mpOptionsDialog;
  QGroupBox *mpGeneralGroupBox;
  Label *mpOutputSizeLabel;
  QSpinBox *mpOutputSizeSpinBox;
  QCheckBox *mpResetMessagesNumberBeforeSimulationCheckBox;
  QCheckBox *mpClearMessagesBrowserBeforeSimulationCheckBox;
  QGroupBox *mpFontColorsGroupBox;
  Label *mpFontFamilyLabel;
  QFontComboBox *mpFontFamilyComboBox;
  Label *mpFontSizeLabel;
  DoubleSpinBox *mpFontSizeSpinBox;
  Label *mpNotificationColorLabel;
  QPushButton *mpNotificationColorButton;
  QColor mNotificaitonColor;
  Label *mpWarningColorLabel;
  QPushButton *mpWarningColorButton;
  QColor mWarningColor;
  Label *mpErrorColorLabel;
  QPushButton *mpErrorColorButton;
  QColor mErrorColor;
public slots:
  void pickNotificationColor();
  void pickWarningColor();
  void pickErrorColor();
};

class NotificationsPage : public QWidget
{
  Q_OBJECT
public:
  enum OldFrontend {
    AlwaysAskForOF = 0,
    TryOnceWithOF = 1,
    SwitchPermanentlyToOF = 2,
    KeepUsingNF = 3
  };
  NotificationsPage(OptionsDialog *pOptionsDialog);
  QCheckBox* getQuitApplicationCheckBox() {return mpQuitApplicationCheckBox;}
  QCheckBox* getItemDroppedOnItselfCheckBox() {return mpItemDroppedOnItselfCheckBox;}
  QCheckBox* getReplaceableIfPartialCheckBox() {return mpReplaceableIfPartialCheckBox;}
  QCheckBox* getInnerModelNameChangedCheckBox() {return mpInnerModelNameChangedCheckBox;}
  QCheckBox* getSaveModelForBitmapInsertionCheckBox() {return mpSaveModelForBitmapInsertionCheckBox;}
  QCheckBox* getAlwaysAskForDraggedComponentName() {return mpAlwaysAskForDraggedComponentName;}
  QCheckBox* getAlwaysAskForTextEditorErrorCheckBox() {return mpAlwaysAskForTextEditorErrorCheckBox;}
private:
  OptionsDialog *mpOptionsDialog;
  QGroupBox *mpNotificationsGroupBox;
  QCheckBox *mpQuitApplicationCheckBox;
  QCheckBox *mpItemDroppedOnItselfCheckBox;
  QCheckBox *mpReplaceableIfPartialCheckBox;
  QCheckBox *mpInnerModelNameChangedCheckBox;
  QCheckBox *mpSaveModelForBitmapInsertionCheckBox;
  QCheckBox *mpAlwaysAskForDraggedComponentName;
  QCheckBox *mpAlwaysAskForTextEditorErrorCheckBox;
};

class LineStylePage : public QWidget
{
  Q_OBJECT
public:
  LineStylePage(OptionsDialog *pOptionsDialog);
  void setLineColor(QColor color);
  QColor getLineColor();
  void setLinePickColorButtonIcon();
  void setLinePattern(QString pattern);
  QString getLinePattern();
  void setLineThickness(qreal thickness);
  qreal getLineThickness();
  void setLineStartArrow(QString startArrow);
  QString getLineStartArrow();
  void setLineEndArrow(QString endArrow);
  QString getLineEndArrow();
  void setLineArrowSize(qreal size);
  qreal getLineArrowSize();
  void setLineSmooth(bool smooth);
  bool getLineSmooth();
private:
  OptionsDialog *mpOptionsDialog;
  QGroupBox *mpLineStyleGroupBox;
  Label *mpLineColorLabel;
  QPushButton *mpLinePickColorButton;
  QColor mLineColor;
  Label *mpLinePatternLabel;
  QComboBox *mpLinePatternComboBox;
  Label *mpLineThicknessLabel;
  DoubleSpinBox *mpLineThicknessSpinBox;
  Label *mpLineStartArrowLabel;
  QComboBox *mpLineStartArrowComboBox;
  Label *mpLineEndArrowLabel;
  QComboBox *mpLineEndArrowComboBox;
  Label *mpLineArrowSizeLabel;
  DoubleSpinBox *mpLineArrowSizeSpinBox;
  Label *mpLineSmoothLabel;
  QCheckBox *mpLineSmoothCheckBox;
public slots:
  void linePickColor();
};

class FillStylePage : public QWidget
{
  Q_OBJECT
public:
  FillStylePage(OptionsDialog *pOptionsDialog);
  void setFillColor(QColor color);
  QColor getFillColor();
  void setFillPickColorButtonIcon();
  void setFillPattern(QString pattern);
  QString getFillPattern();
private:
  OptionsDialog *mpOptionsDialog;
  QGroupBox *mpFillStyleGroupBox;
  Label *mpFillColorLabel;
  QPushButton *mpFillPickColorButton;
  QColor mFillColor;
  Label *mpFillPatternLabel;
  QComboBox *mpFillPatternComboBox;
public slots:
  void fillPickColor();
};

class PlottingPage : public QWidget
{
  Q_OBJECT
public:
  PlottingPage(OptionsDialog *pOptionsDialog);
  void setPlottingViewMode(QString value);
  QString getPlottingViewMode();
  QCheckBox* getAutoScaleCheckBox() {return mpAutoScaleCheckBox;}
  QCheckBox* getPrefixUnitsCheckbox() {return mpPrefixUnitsCheckbox;}
  void setCurvePattern(int pattern);
  int getCurvePattern();
  void setCurveThickness(qreal thickness);
  qreal getCurveThickness();
  QSpinBox* getFilterIntervalSpinBox() {return mpFilterIntervalSpinBox;}
  DoubleSpinBox *getTitleFontSizeSpinBox() const {return mpTitleFontSizeSpinBox;}
  DoubleSpinBox *getVerticalAxisTitleFontSizeSpinBox() const {return mpVerticalAxisTitleFontSizeSpinBox;}
  DoubleSpinBox *getVerticalAxisNumbersFontSizeSpinBox() const {return mpVerticalAxisNumbersFontSizeSpinBox;}
  DoubleSpinBox *getHorizontalAxisTitleFontSizeSpinBox() const {return mpHorizontalAxisTitleFontSizeSpinBox;}
  DoubleSpinBox *getHorizontalAxisNumbersFontSizeSpinBox() const {return mpHorizontalAxisNumbersFontSizeSpinBox;}
  DoubleSpinBox *getFooterFontSizeSpinBox() const {return mpFooterFontSizeSpinBox;}
  DoubleSpinBox *getLegendFontSizeSpinBox() const {return mpLegendFontSizeSpinBox;}
private:
  OptionsDialog *mpOptionsDialog;
  QGroupBox *mpGeneralGroupBox;
  QCheckBox *mpAutoScaleCheckBox;
  QCheckBox *mpPrefixUnitsCheckbox;
  QGroupBox *mpPlottingViewModeGroupBox;
  QRadioButton *mpPlottingTabbedViewRadioButton;
  QRadioButton *mpPlottingSubWindowViewRadioButton;
  QGroupBox *mpCurveStyleGroupBox;
  Label *mpCurvePatternLabel;
  QComboBox *mpCurvePatternComboBox;
  Label *mpCurveThicknessLabel;
  DoubleSpinBox *mpCurveThicknessSpinBox;
  QGroupBox *mpVariableFilterGroupBox;
  Label *mpFilterIntervalHelpLabel;
  Label *mpFilterIntervalLabel;
  QSpinBox *mpFilterIntervalSpinBox;
  QGroupBox *mpFontSizeGroupBox;
  Label *mpTitleFontSizeLabel;
  DoubleSpinBox *mpTitleFontSizeSpinBox;
  Label *mpVerticalAxisTitleFontSizeLabel;
  DoubleSpinBox *mpVerticalAxisTitleFontSizeSpinBox;
  Label *mpVerticalAxisNumbersFontSizeLabel;
  DoubleSpinBox *mpVerticalAxisNumbersFontSizeSpinBox;
  Label *mpHorizontalAxisTitleFontSizeLabel;
  DoubleSpinBox *mpHorizontalAxisTitleFontSizeSpinBox;
  Label *mpHorizontalAxisNumbersFontSizeLabel;
  DoubleSpinBox *mpHorizontalAxisNumbersFontSizeSpinBox;
  Label *mpFooterFontSizeLabel;
  DoubleSpinBox *mpFooterFontSizeSpinBox;
  Label *mpLegendFontSizeLabel;
  DoubleSpinBox *mpLegendFontSizeSpinBox;
};

class FigaroPage : public QWidget
{
  Q_OBJECT
public:
  FigaroPage(OptionsDialog *pOptionsDialog);
  QLineEdit* getFigaroDatabaseFileTextBox() {return mpFigaroDatabaseFileTextBox;}
  QLineEdit* getFigaroOptionsTextBox() {return mpFigaroOptionsFileTextBox;}
  QLineEdit* getFigaroProcessTextBox() {return mpFigaroProcessTextBox;}
private:
  OptionsDialog *mpOptionsDialog;
  QGroupBox *mpFigaroGroupBox;
  Label *mpFigaroDatabaseFileLabel;
  QLineEdit *mpFigaroDatabaseFileTextBox;
  QPushButton *mpBrowseFigaroDatabaseFileButton;
  Label *mpFigaroOptionsFileLabel;
  QLineEdit *mpFigaroOptionsFileTextBox;
  QPushButton *mpBrowseFigaroOptionsFileButton;
  Label *mpFigaroProcessLabel;
  QLineEdit *mpFigaroProcessTextBox;
  QPushButton *mpBrowseFigaroProcessButton;
  QPushButton *mpResetFigaroProcessButton;
private slots:
  void browseFigaroLibraryFile();
  void browseFigaroOptionsFile();
  void browseFigaroProcessFile();
  void resetFigaroProcessPath();
};

class DebuggerPage : public QWidget
{
  Q_OBJECT
public:
  DebuggerPage(OptionsDialog *pOptionsDialog);
  void setGDBPath(QString path);
  QString getGDBPath();
  QLineEdit* getGDBPathTextBox() {return mpGDBPathTextBox;}
  QSpinBox* getGDBCommandTimeoutSpinBox() {return mpGDBCommandTimeoutSpinBox;}
  QSpinBox* getGDBOutputLimitSpinBox() {return mpGDBOutputLimitSpinBox;}
  QCheckBox* getDisplayCFramesCheckBox() {return mpDisplayCFramesCheckBox;}
  QCheckBox* getDisplayUnknownFramesCheckBox() {return mpDisplayUnknownFramesCheckBox;}
  QCheckBox* getClearOutputOnNewRunCheckBox() {return mpClearOutputOnNewRunCheckBox;}
  QCheckBox* getClearLogOnNewRunCheckBox() {return mpClearLogOnNewRunCheckBox;}
  QCheckBox* getAlwaysShowTransformationsCheckBox() {return mpAlwaysShowTransformationsCheckBox;}
  QCheckBox* getGenerateOperationsCheckBox() {return mpGenerateOperationsCheckBox;}
private:
  OptionsDialog *mpOptionsDialog;
  QGroupBox *mpAlgorithmicDebuggerGroupBox;
  Label *mpGDBPathLabel;
  QLineEdit *mpGDBPathTextBox;
  QPushButton *mpGDBPathBrowseButton;
  Label *mpGDBCommandTimeoutLabel;
  QSpinBox *mpGDBCommandTimeoutSpinBox;
  Label *mpGDBOutputLimitLabel;
  QSpinBox *mpGDBOutputLimitSpinBox;
  QCheckBox *mpDisplayCFramesCheckBox;
  QCheckBox *mpDisplayUnknownFramesCheckBox;
  QCheckBox *mpClearOutputOnNewRunCheckBox;
  QCheckBox *mpClearLogOnNewRunCheckBox;
  QGroupBox *mpTransformationalDebuggerGroupBox;
  QCheckBox *mpAlwaysShowTransformationsCheckBox;
  QCheckBox *mpGenerateOperationsCheckBox;
public slots:
  void browseGDBPath();
};

class FMIPage : public QWidget
{
  Q_OBJECT
public:
  FMIPage(OptionsDialog *pOptionsDialog);
  void setFMIExportVersion(QString version);
  QString getFMIExportVersion();
  void setFMIExportType(QString type);
  QString getFMIExportType();
  QString getFMIFlags();
  QLineEdit* getFMUNameTextBox() {return mpFMUNameTextBox;}
  QLineEdit* getMoveFMUTextBox() {return mpMoveFMUTextBox;}
  QGroupBox* getPlatformsGroupBox() {return mpPlatformsGroupBox;}
  QComboBox *getModelDescriptionFiltersComboBox() const {return mpModelDescriptionFiltersComboBox;}
  QComboBox *getSolverForCoSimulationComboBox() const {return mpSolverForCoSimulationComboBox;}
  QCheckBox *getIncludeResourcesCheckBox() const {return mpIncludeResourcesCheckBox;}
  QCheckBox *getIncludeSourceCodeCheckBox() const {return mpIncludeSourceCodeCheckBox;}
  QCheckBox *getGenerateDebugSymbolsCheckBox() const {return mpGenerateDebugSymbolsCheckBox;}
  QCheckBox* getDeleteFMUDirectoryAndModelCheckBox() {return mpDeleteFMUDirectoryAndModelCheckBox;}

  static const QString FMU_FULL_CLASS_NAME_DOTS_PLACEHOLDER;
  static const QString FMU_FULL_CLASS_NAME_UNDERSCORES_PLACEHOLDER;
  static const QString FMU_SHORT_CLASS_NAME_PLACEHOLDER;
private:
  OptionsDialog *mpOptionsDialog;
  QGroupBox *mpExportGroupBox;
  QGroupBox *mpVersionGroupBox;
  QRadioButton *mpVersion1RadioButton;
  QRadioButton *mpVersion2RadioButton;
  QGroupBox *mpTypeGroupBox;
  QRadioButton *mpModelExchangeRadioButton;
  QRadioButton *mpCoSimulationRadioButton;
  QRadioButton *mpModelExchangeCoSimulationRadioButton;
  Label *mpFMUNameLabel;
  Label *mpMoveFMULabel;
  QLineEdit *mpFMUNameTextBox;
  QLineEdit *mpMoveFMUTextBox;
  QPushButton *mpBrowseFMUDirectoryButton;
  QGroupBox *mpPlatformsGroupBox;
  QComboBox *mpSolverForCoSimulationComboBox;
  QComboBox *mpModelDescriptionFiltersComboBox;
  QCheckBox *mpIncludeResourcesCheckBox;
  QCheckBox *mpIncludeSourceCodeCheckBox;
  QCheckBox *mpGenerateDebugSymbolsCheckBox;
  QGroupBox *mpImportGroupBox;
  QCheckBox *mpDeleteFMUDirectoryAndModelCheckBox;
public slots:
  void selectFMUDirectory();
  void enableIncludeSourcesCheckBox(QString modelDescriptionFilter);
};

class TLMPage : public QWidget
{
  Q_OBJECT
public:
  TLMPage(OptionsDialog *pOptionsDialog);
  QString getOMTLMSimulatorPath();
  QString getOMTLMSimulatorManagerPath();
  QString getOMTLMSimulatorMonitorPath();
  QLineEdit* getTLMPluginPathTextBox() {return mpTLMPluginPathTextBox;}
  QLineEdit* getTLMManagerProcessTextBox() {return mpTLMManagerProcessTextBox;}
  QLineEdit* getTLMMonitorProcessTextBox() {return mpTLMMonitorProcessTextBox;}
private:
  OptionsDialog *mpOptionsDialog;
  QGroupBox *mpGeneralGroupBox;
  Label *mpTLMPluginPathLabel;
  QLineEdit *mpTLMPluginPathTextBox;
  QPushButton *mpBrowseTLMPluginPathButton;
  Label *mpTLMManagerProcessLabel;
  QLineEdit *mpTLMManagerProcessTextBox;
  QPushButton *mpBrowseTLMManagerProcessButton;
  Label *mpTLMMonitorProcessLabel;
  QLineEdit *mpTLMMonitorProcessTextBox;
  QPushButton *mpBrowseTLMMonitorProcessButton;
private slots:
  void browseTLMPluginPath();
  void browseTLMManagerProcess();
  void browseTLMMonitorProcess();
};

class OMSimulatorPage : public QWidget
{
  Q_OBJECT
public:
  OMSimulatorPage(OptionsDialog *pOptionsDialog);
  QComboBox* getLoggingLevelComboBox() {return mpLoggingLevelComboBox;}
  QLineEdit* getCommandLineOptionsTextBox() {return mpCommandLineOptionsTextBox;}
private:
  OptionsDialog *mpOptionsDialog;
  QGroupBox *mpGeneralGroupBox;
  Label *mpLoggingLevelLabel;
  QComboBox *mpLoggingLevelComboBox;
  Label *mpCommandLineOptionsLabel;
  QLineEdit *mpCommandLineOptionsTextBox;
};

class TraceabilityPage : public QWidget
{
  Q_OBJECT
public:
  TraceabilityPage(OptionsDialog *pOptionsDialog);
  QGroupBox* getTraceabilityGroupBox() {return mpTraceabilityGroupBox;}
//  QLineEdit* getFMUOutputDirectory() {return mpFMUOutputDirectoryTextBox;}
//  QPushButton *mpBrowseFMUOutputDirectoryButton;
  QPushButton *mpBrowseGitRepositoryButton;
  QLineEdit* getTraceabilityDaemonIpAdress() {return mpTraceabilityDaemonIpAdressTextBox;}
  QLineEdit* getTraceabilityDaemonPort() {return mpTraceabilityDaemonPortTextBox;}
  QLineEdit* getUserName() {return mpUserNameTextBox;}
  QLineEdit* getEmail() {return mpEmailTextBox;}
  QLineEdit* getGitRepository() {return mpGitRepositoryTextBox;}
private:
  OptionsDialog *mpOptionsDialog;
  QGroupBox *mpTraceabilityGroupBox;
  Label *mpUserNameLabel;
  QLineEdit *mpUserNameTextBox;
  Label *mpEmailLabel;
  QLineEdit *mpEmailTextBox;
  Label *mpGitRepositoryLabel;
  QLineEdit *mpGitRepositoryTextBox;
//  Label *mpFMUOutputDirectoryLabel;
//  QLineEdit *mpFMUOutputDirectoryTextBox;
  Label *mpTraceabilityDaemonIpAdressLabel;
  QLineEdit *mpTraceabilityDaemonIpAdressTextBox;
  Label *mpTraceabilityDaemonPortLabel;
  QLineEdit *mpTraceabilityDaemonPortTextBox;
private slots:
//  void browseFMUOutputDirectory();
  void browseGitRepository();

};

class DiscardLocalTranslationFlagsDialog : public QDialog
{
  Q_OBJECT
public:
  DiscardLocalTranslationFlagsDialog(QWidget *pParent = 0);
private:
  Label *mpDescriptionLabel;
  Label *mpDescriptionLabel2;
  QListWidget *mpClassesWithLocalTranslationFlagsListWidget;
  QPushButton *mpYesButton;
  QPushButton *mpNoButton;
  QDialogButtonBox *mpButtonBox;

  void listLocalTranslationFlagsClasses(LibraryTreeItem *pLibraryTreeItem);
private slots:
  void selectUnSelectAll(bool checked);
  void discardLocalTranslationFlags();
  void showLocalTranslationFlags(QListWidgetItem *pListWidgetItem);
public slots:
  int exec();
};

#endif // OPTIONSDIALOG_H
