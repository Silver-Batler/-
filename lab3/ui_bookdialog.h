/********************************************************************************
** Form generated from reading UI file 'bookdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKDIALOG_H
#define UI_BOOKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BookDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *titleLabel;
    QLineEdit *titleLineEdit;
    QLabel *authorLabel;
    QLineEdit *authorLineEdit;
    QLabel *yearLabel;
    QLineEdit *yearLineEdit;
    QLabel *genreLabel;
    QComboBox *genreComboBox;
    QLabel *pagesLabel;
    QLineEdit *pagesLineEdit;
    QLabel *ratingLabel;
    QLineEdit *ratingLineEdit;
    QLabel *bestsellerLabel;
    QCheckBox *bestsellerCheckBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *BookDialog)
    {
        if (BookDialog->objectName().isEmpty())
            BookDialog->setObjectName(QString::fromUtf8("BookDialog"));
        BookDialog->resize(400, 350);
        verticalLayout = new QVBoxLayout(BookDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        titleLabel = new QLabel(BookDialog);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, titleLabel);

        titleLineEdit = new QLineEdit(BookDialog);
        titleLineEdit->setObjectName(QString::fromUtf8("titleLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, titleLineEdit);

        authorLabel = new QLabel(BookDialog);
        authorLabel->setObjectName(QString::fromUtf8("authorLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, authorLabel);

        authorLineEdit = new QLineEdit(BookDialog);
        authorLineEdit->setObjectName(QString::fromUtf8("authorLineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, authorLineEdit);

        yearLabel = new QLabel(BookDialog);
        yearLabel->setObjectName(QString::fromUtf8("yearLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, yearLabel);

        yearLineEdit = new QLineEdit(BookDialog);
        yearLineEdit->setObjectName(QString::fromUtf8("yearLineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, yearLineEdit);

        genreLabel = new QLabel(BookDialog);
        genreLabel->setObjectName(QString::fromUtf8("genreLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, genreLabel);

        genreComboBox = new QComboBox(BookDialog);
        genreComboBox->setObjectName(QString::fromUtf8("genreComboBox"));

        formLayout->setWidget(3, QFormLayout::FieldRole, genreComboBox);

        pagesLabel = new QLabel(BookDialog);
        pagesLabel->setObjectName(QString::fromUtf8("pagesLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, pagesLabel);

        pagesLineEdit = new QLineEdit(BookDialog);
        pagesLineEdit->setObjectName(QString::fromUtf8("pagesLineEdit"));

        formLayout->setWidget(4, QFormLayout::FieldRole, pagesLineEdit);

        ratingLabel = new QLabel(BookDialog);
        ratingLabel->setObjectName(QString::fromUtf8("ratingLabel"));

        formLayout->setWidget(5, QFormLayout::LabelRole, ratingLabel);

        ratingLineEdit = new QLineEdit(BookDialog);
        ratingLineEdit->setObjectName(QString::fromUtf8("ratingLineEdit"));

        formLayout->setWidget(5, QFormLayout::FieldRole, ratingLineEdit);

        bestsellerLabel = new QLabel(BookDialog);
        bestsellerLabel->setObjectName(QString::fromUtf8("bestsellerLabel"));

        formLayout->setWidget(6, QFormLayout::LabelRole, bestsellerLabel);

        bestsellerCheckBox = new QCheckBox(BookDialog);
        bestsellerCheckBox->setObjectName(QString::fromUtf8("bestsellerCheckBox"));

        formLayout->setWidget(6, QFormLayout::FieldRole, bestsellerCheckBox);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(BookDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(BookDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), BookDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), BookDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(BookDialog);
    } // setupUi

    void retranslateUi(QDialog *BookDialog)
    {
        BookDialog->setWindowTitle(QCoreApplication::translate("BookDialog", "\320\232\320\275\320\270\320\263\320\260", nullptr));
        titleLabel->setText(QCoreApplication::translate("BookDialog", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265:", nullptr));
        titleLineEdit->setPlaceholderText(QCoreApplication::translate("BookDialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\272\320\275\320\270\320\263\320\270", nullptr));
        authorLabel->setText(QCoreApplication::translate("BookDialog", "\320\220\320\262\321\202\320\276\321\200:", nullptr));
        authorLineEdit->setPlaceholderText(QCoreApplication::translate("BookDialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\270\320\274\321\217 \320\260\320\262\321\202\320\276\321\200\320\260", nullptr));
        yearLabel->setText(QCoreApplication::translate("BookDialog", "\320\223\320\276\320\264 \320\270\320\267\320\264\320\260\320\275\320\270\321\217:", nullptr));
        yearLineEdit->setPlaceholderText(QCoreApplication::translate("BookDialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\263\320\276\320\264 \320\270\320\267\320\264\320\260\320\275\320\270\321\217 (1000-2100)", nullptr));
        genreLabel->setText(QCoreApplication::translate("BookDialog", "\320\226\320\260\320\275\321\200:", nullptr));
        pagesLabel->setText(QCoreApplication::translate("BookDialog", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\201\321\202\321\200\320\260\320\275\320\270\321\206:", nullptr));
        pagesLineEdit->setPlaceholderText(QCoreApplication::translate("BookDialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\201\321\202\321\200\320\260\320\275\320\270\321\206", nullptr));
        ratingLabel->setText(QCoreApplication::translate("BookDialog", "\320\240\320\265\320\271\321\202\320\270\320\275\320\263:", nullptr));
        ratingLineEdit->setPlaceholderText(QCoreApplication::translate("BookDialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\200\320\265\320\271\321\202\320\270\320\275\320\263 (0.0-10.0)", nullptr));
        bestsellerLabel->setText(QCoreApplication::translate("BookDialog", "\320\221\320\265\321\201\321\202\321\201\320\265\320\273\320\273\320\265\321\200:", nullptr));
        bestsellerCheckBox->setText(QCoreApplication::translate("BookDialog", "\320\257\320\262\320\273\321\217\320\265\321\202\321\201\321\217 \320\261\320\265\321\201\321\202\321\201\320\265\320\273\320\273\320\265\321\200\320\276\320\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BookDialog: public Ui_BookDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKDIALOG_H
