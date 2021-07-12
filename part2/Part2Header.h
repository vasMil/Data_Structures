#pragma once
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "MergeSortTemplate.h"

class node;
class BST;
class Hashing;

int getDayFile(std::fstream& arx, int pos);
void GetMyNode(std::string filename, std::vector<node>& vect);

int dateFix(std::string fdate);

void Amenu(std::vector<node> &inp);
void Bmenu(std::vector<node> &inp);
void Cmenu(std::vector<node>& inp);
void MainMenu(std::vector<node>& inp);
void TreeMenu(std::vector<node>& inp);