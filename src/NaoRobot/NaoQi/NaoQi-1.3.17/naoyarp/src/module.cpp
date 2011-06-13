/**
 * @author Alexandros Paraschos
 *
 * Version : $Id$
 * This file was generated by Aldebaran Robotics ModuleGenerator
 */

#include <iostream>
#include "module.h"
#include "alproxy.h"
#include "alptr.h"
#include "albroker.h"

#include "NaoRobot/ALBrokerWrapperClass.h"
#include "NaoJointChain.h"
#include "YarpDev/YarpJointDev.h"

using namespace AL;

//______________________________________________
// constructor
//______________________________________________
module::module ( ALPtr<ALBroker> pBroker, const std::string& pName ) : ALModule ( pBroker, pName ) {
    setModuleDescription ( "This an autogenerated module, this description needs to be updated." );

    functionName ( "DummyFunction", "module" ,  "An autogenerated dummyFunction." );
    addParam ( "msg", "A string describing a message: the module will say this message when this method is called." );
    addParam ( "foo", "An example parameter." );
    setReturn ( "return", "Returns the foo param." );
    BIND_METHOD ( module::dummyFunction );


    ALBrokerWrapper::Instance().SetBroker ( pBroker );

    boost::shared_ptr<NaoJointChain> c ( new NaoJointChain ( "Head" ) );
    std::cout << "----------------------------------" << std::endl;
    boost::shared_ptr<NaoJointChain> c1 ( new NaoJointChain ( "LArm" ) );
    std::cout << "----------------------------------" << std::endl;
    boost::shared_ptr<NaoJointChain> c2 ( new NaoJointChain ( "RArm" ) );
    std::cout << "----------------------------------" << std::endl;
    boost::shared_ptr<NaoJointChain> c3 ( new NaoJointChain ( "LLeg" ) );
    std::cout << "----------------------------------" << std::endl;
    boost::shared_ptr<NaoJointChain> c4 ( new NaoJointChain ( "RLeg" ) );
    YarpJointDev b ( c );

    usleep ( 1000000 );


    bool res = b.setImpedance ( 1, 1.0f, 0, 0 );

    usleep ( 1000000 );

    res &= b.positionMove ( 1, 1.1f );

    usleep ( 1000000 );

    res &= b.setImpedance ( 1, 0.0f, 0, 0 );

    NaoJoint j("HeadPitch");
    j.ChangeAngle(1.1,2);
    j.ChangeAngleBlock(1.1,2);
    float xj = j.GetCurrentAngle();
    std::vector<float> range;
    j.GetRange(range);
    float  stiff = j.GetStiffness();
    j.GotoAngle(xj,3);
    j.GotoAngleBlock(xj,2);
    j.SetStiffness(stiff);

    NaoJointChain ch ("LLeg");
    std::vector<float> gotoAngles;
    gotoAngles.push_back(1.1);
    gotoAngles.push_back(1.1);
    gotoAngles.push_back(1.1);
    ch.ChangeAngle(gotoAngles,0.8);
    ch.ChangeAngleBlock(gotoAngles,0.1);
    ch.GetCurrentAngles();
    ch.GetNumberOfJoints();
    std::vector<float> pos = ch.GetPotision();
    ch.GetSpecificJoint(2);
    std::vector<float> stiffnesses = ch.GetStiffness();
    ch.GotoAngle(gotoAngles,1.1);
    ch.GotoAngleBlock(gotoAngles,1.1);
    ch.GotoPosition(pos,1,true);
    ch.GotoPositionBlock(pos,1,true);
    ch.SetStiffness(stiffnesses);



}

//______________________________________________
// destructor
//______________________________________________
module::~module() {

}

//______________________________________________
// version
//______________________________________________
std::string module::version() {
    return ALTOOLS_VERSION ( NAOYARP );
}

/**
 * dataChanged. Called by ALMemory when subcription
 * has been modified.
 * @param pDataName, name of the suscribed data
 * @param pValue, value of the suscribed data
 * @param pMessage, message written by user during suscription
 */
void module::dataChanged ( const std::string& pDataName, const ALValue& pValue, const std::string& pMessage ) {

}

/**
 * innerTest
 */
bool module::innerTest() {
    bool result = true;
    // TODO: write module test code
    return result;
}

/**
 * dummy Function
 * @param pMsg Message to show on screen
 * @param pFoo the function will return this parameter
 * @return an alvalue
 */
ALValue module::dummyFunction ( const std::string& pMsg, const ALValue& pFoo ) {
    std::cout << "module says : " << pMsg << std::endl;

    if ( pFoo.isValid() )
        std::cout << "Return value: " << pFoo.toString ( VerbosityMini ) << std::endl;
    else
        std::cout << "The value you sent me is invalid." << std::endl;

    return pFoo;
}

