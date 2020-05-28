// Counts the sentences in the text

void count_sentences (TXT *texto)
{
    int i = 0;

    while (i < texto->length)
    {
        if (texto->text[i] == '.' || texto->text[i] == '!' || texto->text[i] == '?')
        {
            texto->sentences += 1;
        }
        i++;
    }
}
