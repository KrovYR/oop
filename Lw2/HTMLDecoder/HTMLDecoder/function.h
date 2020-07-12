#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <unordered_map>

std::string ReadHTML(std::istream& stream);

std::pair<std::string, size_t> GetClosestHTMLEntity(const std::string& html, size_t startPos);

std::string DecodeHTML(const std::string& html);

void PrintHTML(const std::string& html, std::ostream& outStream);