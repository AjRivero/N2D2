
/*
    (C) Copyright 2016 CEA LIST. All Rights Reserved.
    Contributor(s): Olivier BICHLER (olivier.bichler@cea.fr)
                    David BRIAND (david.briand@cea.fr)

    This software is governed by the CeCILL-C license under French law and
    abiding by the rules of distribution of free software.  You can  use,
    modify and/ or redistribute the software under the terms of the CeCILL-C
    license as circulated by CEA, CNRS and INRIA at the following URL
    "http://www.cecill.info".

    As a counterpart to the access to the source code and  rights to copy,
    modify and redistribute granted by the license, users are provided only
    with a limited warranty  and the software's author,  the holder of the
    economic rights,  and the successive licensors  have only  limited
    liability.

    The fact that you are presently reading this means that you have had
    knowledge of the CeCILL-C license and that you accept its terms.
*/

#ifndef N2D2_DAIMLER_DATABASE_H
#define N2D2_DAIMLER_DATABASE_H

#include "Database.hpp"
#include "Database/DIR_Database.hpp"

namespace N2D2 {
class Daimler_Database : public DIR_Database {
public:
    Daimler_Database(double learn, double validation, double test, bool fully);
    virtual void load(const std::string& dataPath,
                      const std::string& labelPath = "",
                      bool /*extractROIs*/ = false);
    virtual ~Daimler_Database() {};

protected:
    void loadDaimlerStimuliPerDir(const std::string& dirPath);
    void loadDaimlerTestStimuli(const std::string& dirPath,
                                const std::string& labelPath);

    double mLearn;
    double mValidation;
    double mTest;
    bool mFully;
};
}

#endif // N2D2_DAIMLER_DATABASE_H