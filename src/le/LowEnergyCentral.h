/*
 * Copyright (C) 2018 EPFL
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/.
 */

/**
 * @file LowEenergyCentral.h
 * @brief A Bluetooth Low Energy central controller
 * @author Ayberk Özgür
 */

#ifndef LOWENERGYCENTRAL_H
#define LOWENERGYCENTRAL_H

#include <QQuickItem>
#include <QLowEnergyController>

namespace QMLBluetoothExtras {

/**
 * @brief Bluetooth Low Energy central controller
 */
class LowEnergyCentral : public QQuickItem {
    /* *INDENT-OFF* */
    Q_OBJECT
    /* *INDENT-ON* */



public:

    /** @cond DO_NOT_DOCUMENT */

    /**
     * @brief Creates a new Bluetooth Low Energy controller
     *
     * @param parent Parent of this QML item
     */
    LowEnergyCentral(QQuickItem* parent = 0);

    /**
     * @brief Destroys this Bluetooth Low Energy Controller
     */
    virtual ~LowEnergyCentral();

    /** @endcond */

signals:



    /** @cond DO_NOT_DOCUMENT */



    /** @endcond */

public slots:

    void connectToDevice();

private slots:



private:

    QLowEnergyController* controller; ///< Underlying controller

};

}

#endif // LOWENERGYCENTRAL_H
