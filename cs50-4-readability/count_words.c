// Counts the words in the text

void count_words (TXT *texto)
{
    int temp;
    int i = 0;

    while (texto->text[i] != '\0')
    {
        temp = isalpha(texto->text[i]);
        if (temp != 0)
        {
            texto->words += 1;
            while (texto->text[i] != ' ' && texto->text[i + 1] != '\0')
            {
                i++;
            }
        }
        i++;
    }
}
