// Counts the letters in the text

void count_letters (TXT *texto)
{
    int temp;
    int i = 0;

    while (texto->text[i] != '\0')
    {
        temp = isalpha(texto->text[i]);

        if (temp != 0)
        {
            texto->letters += 1;
        }
        i++;
    }
}
