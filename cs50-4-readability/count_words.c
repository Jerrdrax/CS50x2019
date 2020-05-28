// Counts the words in the text

void count_words (TXT *texto)
{
    int temp;
    int i = 0;

    while (i < texto->length)
    {
        temp = isalpha(texto->text[i]);
        if (temp != 0)
        {
            texto->words += 1;
            while (texto->text[i] != ' ' && i < texto->length)
            {
                i++;
            }
        }
        i++;
    }
}
