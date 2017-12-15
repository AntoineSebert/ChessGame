/**
	@author Antoine "Anthony" Sébert
	@creation_date 10/12/2017
	@description palettes for graphical interface
*/

#pragma once

#include <array>

typedef std::array<double, 4> rgba;
typedef std::array<double, 3> rgb;

const rgba BLACK = { 0.0, 0.0, 0.0, 1.0 };
const rgba BLEU = { 0.0, 0.0, 1.0, 1.0 };
const rgba GREEN = { 0.0, 1.0, 0.0, 1.0 };
const rgba CYAN = { 0.0, 1.0, 1.0, 1.0 };
const rgba RED = { 1.0, 0.0, 0.0, 1.0 };
const rgba MAGENTA = { 1.0, 0.0, 1.0, 1.0 };
const rgba YELLOW = { 1.0, 1.0, 0.0, 1.0 };
const rgba WHITE = { 1.0, 1.0, 1.0, 1.0 };

// how ?