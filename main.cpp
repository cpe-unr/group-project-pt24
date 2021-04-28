/** @file */

//Authors: Samuel DeLange, Jamie Lee, Nikhil Sharma
//Group Project
//4/22/2021

#include <iostream>

using namespace std;
/**
 * \brief   The function bar.
 *
 * \details This function does something which is doing nothing. So this text
 *          is totally senseless and you really do not need to read this,
 *          because this text is basically saying nothing.
 *
 * \note    This text shall only show you, how such a \"note\" section
 *          is looking. There is nothing which really needs your notice,
 *          so you do not really need to read this section.
 *
 * \param[in]     a    Description of parameter a.
 * \param[out]    b    Description of the parameter b.
 * \param[in,out] c    Description of the parameter c.
 *
 * \return        The error return code of the function.
 *
 * \retval        ERR_SUCCESS    The function is successfully executed
 * \retval        ERR_FAILURE    An error occurred
 */
void fn(){

}

int main() {
	int userChoice;
	string fileChoice;
	cout << "Please choose from one of the options below" << endl;
	cout << "1. Metadata" << endl;
	cout << "2. Audio Processors" << endl;
	cout << "3. Generate CSV " << endl;
	cin >> userChoice;
	
	switch(userChoice){
		case 1:
			subMenuMD();
			break;
		case 2:	
			subMenuAP()	
			break;
		case 3:
			break;
		default:
			cout << "Please enter a valid option!" << endl;
	}
	//cout << "Hello, World!" << endl;
	Wav wav;
//	wav.readFile(fileChoice);
//	Processor *processor = new Echo(10);
//	processor->processBuffer(wav.getBuffer(), wav.getBufferSize());
//	wav.writeFile(echofile);
//	delete processor;

//	wav.readFile(fileChoice);
//	Processor *limit = new Limiter();
//	limit->processBuffer(wav.getBuffer(), wav.getBufferSize());
//	wav.writeFile(limitfile);
//	delete limit;

//	wav.readFile(fileChoice);
//	Processor *noise = new NoiseGate();
//	noise->processBuffer(wav.getBuffer(), wav.getBufferSize());
//	wav.writeFile(noisefile);
//	delete noise;
	return 0;
}
void subMenuMD();
void subMenuAP();
