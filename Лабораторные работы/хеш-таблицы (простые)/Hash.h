#pragma once

double A = 0.143592753589793;

int getHash(int k)
{
    return static_cast<int>(M * (k * A - static_cast<int>(k * A)));
}

int getHash(string text)
{
    int result = 0;
    for (int i = 0; i < int(text.size()); ++i)
    {
        result += static_cast<int>(pow(text[i], 2) * (2 / sqrt(M)) + abs(text[i] * (1 / sqrt(2))));
    }
    return getHash(abs(result));
}