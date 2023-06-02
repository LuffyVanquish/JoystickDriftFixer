#include <Windows.h>
#include <Xinput.h>
#include <iostream>

int main()
{
    // Vérifier la disponibilité de XInput
    XINPUT_STATE state;
    DWORD result = XInputGetState(0, &state);
    if (result != ERROR_SUCCESS)
    {
        std::cout << "Erreur lors de la récupération de l'état de la manette." << std::endl;
        return 1;
    }


    WORD previousButtons = NULL;
    // Boucle de jeu
    while (true)
    {
        // Récupérer l'état de la manette
        result = XInputGetState(0, &state);
        if (result == ERROR_DEVICE_NOT_CONNECTED)
        {
            std::cout << "La manette n'est pas connectée." << std::endl;
            continue;
        }
        else if (result != ERROR_SUCCESS)
        {
            std::cout << "Erreur lors de la récupération de l'état de la manette." << std::endl;
            break;
        }

        // Vérifier les boutons de la manette

        WORD currentButtons = state.Gamepad.wButtons;

        //Permet un appuie unique
        if (currentButtons != previousButtons)
        {            
            previousButtons=currentButtons;
            switch (currentButtons)
            {
            //Boutons
            case XINPUT_GAMEPAD_A:
                std::cout << "Bouton A appuyé." << std::endl;
                break;
            case XINPUT_GAMEPAD_B:
                std::cout << "Bouton B appuyé." << std::endl;
                break;
            case XINPUT_GAMEPAD_X:
                std::cout << "Bouton X appuyé." << std::endl;
                break;
            case XINPUT_GAMEPAD_Y:
                std::cout << "Bouton Y appuyé." << std::endl;
                break;

            //Croix directionnelle
            case XINPUT_GAMEPAD_DPAD_DOWN:
                std::cout << "Croix bas appuyé." << std::endl;
                break;
            case XINPUT_GAMEPAD_DPAD_UP:
                std::cout << "Croix haut appuyé." << std::endl;
                break;
            case XINPUT_GAMEPAD_DPAD_LEFT:
                std::cout << "Croix gauche appuyé." << std::endl;
                break;
            case XINPUT_GAMEPAD_DPAD_RIGHT:
                std::cout << "Croix droite appuyé." << std::endl;
                break;

            //Gachettes
            case XINPUT_GAMEPAD_LEFT_SHOULDER:
                std::cout << "Gachette haute gauche appuyé." << std::endl;
                break;
            case XINPUT_GAMEPAD_RIGHT_SHOULDER:
                std::cout << "Gachette haute droite appuyé." << std::endl;
                break;

            //Joystick appuie
            case XINPUT_GAMEPAD_LEFT_THUMB:
                std::cout << "Joystick gauche appuyé." << std::endl;
                break;
            case XINPUT_GAMEPAD_RIGHT_THUMB:
                std::cout << "Joystick droite appuyé." << std::endl;
                break;

            //Bouton menu
            case XINPUT_GAMEPAD_BACK:
                std::cout << "Button back appuyé." << std::endl;
                break;
            case XINPUT_GAMEPAD_START:
                std::cout << "Button start appuyé." << std::endl;
                break;

            case 0:
            break;

            default:
                std::cout << currentButtons << std::endl;
                break;
            }
        }

        // Récupérer les valeurs des gâchettes basses
        BYTE leftTrigger = state.Gamepad.bLeftTrigger;
        BYTE rightTrigger = state.Gamepad.bRightTrigger;

        //std::cout << "Left trigger Y : " << static_cast<int>(leftTrigger) << " | Right trigger Y : " << static_cast<int>(rightTrigger) << std::endl;

        // Lire les valeurs des joysticks
        SHORT thumbLX = state.Gamepad.sThumbLX;
        SHORT thumbLY = state.Gamepad.sThumbLY;
        SHORT thumbRX = state.Gamepad.sThumbRX;
        SHORT thumbRY = state.Gamepad.sThumbRY;

        // Utilisez les valeurs des joysticks comme bon vous semble

        //std::cout << "Left Y : " << thumbLY << " | Right Y : " << thumbRY << std::endl;


        // Pause pour ne pas surcharger la boucle
        Sleep(100);
    }

    return 0;
}
