#include "fonctions.h"

void font_police(sudoku *sudoku_tab)
{
    TTF_Font* font = TTF_OpenFont("Kichenset.otf", FONT_SIZE);
    for (int x = 0; x < 9; x++)
    {
        char str[2];
        str[0] = x + '1';
        str[1] = 0;
        SDL_Surface* text = TTF_RenderText_Blended(font, str, (SDL_Color){ 255, 255, 255, 255});
        sudoku_tab->cellTextures[x] = SDL_CreateTextureFromSurface(sudoku_tab -> renderer, text);
        SDL_FreeSurface(text);
    }
    TTF_CloseFont(font);
}

void end_message(sudoku *sudoku_tab)
{
    SDL_Surface* victory = TTF_RenderText_Blended(sudoku_tab -> font, "Félicitations cette grille est valide!", (SDL_Color){ 0, 255, 0, 255});
    sudoku_tab -> victory = SDL_CreateTextureFromSurface(sudoku_tab -> renderer, victory);
    SDL_FreeSurface(victory);
    SDL_Surface* loosing = TTF_RenderText_Blended(sudoku_tab -> font, "Raté espece de gros nul!", (SDL_Color){ 255, 0, 0, 255});
    sudoku_tab -> loosing = SDL_CreateTextureFromSurface(sudoku_tab -> renderer, loosing);
    SDL_FreeSurface(loosing);
}