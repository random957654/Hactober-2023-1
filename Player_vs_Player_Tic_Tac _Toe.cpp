#include "myForm.h"
using namespace System;
using namespace System::Windows::Forms;

ref class TicTacToeForm : public System::Windows::Forms::Form
{
private:
    array<Button^>^ buttons;
    bool Player;

public:
    TicTacToeForm()
    {
        Player = true;

        this->Text = "Tic Tac Toe Game";
        this->Size = System::Drawing::Size(450, 450);

        InitializeButtons();
        PlayerSelection();
    }

private:
    void InitializeButtons()
    {
        buttons = gcnew array<Button^>(9);

        int buttonSize = 80;
        int x = 20;
        int y = 20;

        for (int i = 0; i < 9; i++)
        {
            buttons[i] = gcnew Button();
            buttons[i]->Size = System::Drawing::Size(buttonSize, buttonSize);
            buttons[i]->Location = System::Drawing::Point(x, y);
            buttons[i]->Click += gcnew System::EventHandler(this, &TicTacToeForm::Button_Click);
            buttons[i]->Font = gcnew System::Drawing::Font("Arial", 24);
            this->Controls->Add(buttons[i]);

            x += buttonSize + 10;

            if ((i + 1) % 3 == 0)
            {
                x = 20;
                y += buttonSize + 10;
            }
        }
    }

    void PlayerSelection()
    {
        Label^ playerLabel = gcnew Label();
        playerLabel->Text = "Select starting player:";
        playerLabel->Location = System::Drawing::Point(20, 300);
        this->Controls->Add(playerLabel);

        ComboBox^ playerSelection = gcnew ComboBox();
        playerSelection->Items->Add("Player X");
        playerSelection->Items->Add("Player O");
        playerSelection->SelectedIndex = 0;
        playerSelection->Location = System::Drawing::Point(150, 300);
        playerSelection->DropDownStyle = ComboBoxStyle::DropDownList;
        playerSelection->SelectedIndexChanged += gcnew System::EventHandler(this, &TicTacToeForm::Changed_PlayerSelection);
        this->Controls->Add(playerSelection);

        Player = (playerSelection->SelectedIndex == 0);
    }

    void Changed_PlayerSelection(Object^ sender, EventArgs^ e)
    {
        ComboBox^ playerSelection = safe_cast<ComboBox^>(sender);
        Player = (playerSelection->SelectedIndex == 0); // Set player based on the selected index
    }

    void Button_Click(Object^ sender, EventArgs^ e)
    {
        Button^ clickedButton = safe_cast<Button^>(sender);

        if (clickedButton->Text == "")
        {
            clickedButton->Text = Player ? "X" : "O";
            Player = !Player;

            if (CheckForWinner())
            {
                String^ winner = Player ? "O" : "X";
                MessageBox::Show("Player " + winner + " wins!");
                GameReset();
            }
            else if (BoardFull())
            {
                MessageBox::Show("It's a draw!");
                GameReset();
            }
        }
    }

    bool CheckForWinner()
    {
        //Each subarray represents a winning combination.
        array<array<int>^>^ winConditions = {
            gcnew array<int>{0, 1, 2}, // Row 1
            gcnew array<int>{3, 4, 5}, // Row 2
            gcnew array<int>{6, 7, 8}, // Row 3
            gcnew array<int>{0, 3, 6}, // Column 1
            gcnew array<int>{1, 4, 7}, // Column 2
            gcnew array<int>{2, 5, 8}, // Column 3
            gcnew array<int>{0, 4, 8}, // Diagonal 1
            gcnew array<int>{2, 4, 6}  // Diagonal 2
        };

        for each (array<int> ^ winCombination in winConditions)
        {
            int a = winCombination[0];
            int b = winCombination[1];
            int c = winCombination[2];

            if (buttons[a]->Text != "" && buttons[a]->Text == buttons[b]->Text && buttons[b]->Text == buttons[c]->Text)
            {
                buttons[a]->BackColor = System::Drawing::Color::Green;
                buttons[b]->BackColor = System::Drawing::Color::Green;
                buttons[c]->BackColor = System::Drawing::Color::Green;
                return true;
            }
        }
        return false;
    }

    bool BoardFull()
    {
        for each (Button ^ button in buttons)
        {
            if (button->Text == "")
                return false; // Board is not full
        }
        return true; 
    }

    void GameReset()
    {
        for each (Button ^ button in buttons)
        {
            button->Text = "";
            button->BackColor = System::Drawing::SystemColors::Control;
        }

        Player = true;

        for each (Control ^ control in this->Controls)
        {
            ComboBox^ comboBox = dynamic_cast<ComboBox^>(control);
            if (comboBox != nullptr)
            {
                comboBox->SelectedIndex = 0; //Default selection (Player X)
            }
        }
    }
};

int main()
{
    Application::EnableVisualStyles();
    Application::Run(gcnew TicTacToeForm());
    return 0;
}