#include "function.h"

static const std::unordered_map<std::string, std::string> HTML_ENTITY_MAP{
        {"&lt;", "<"},
        {"&gt;", ">"},
        {"&quot;", "\""},
        {"&apos;", "'"},
        {"&amp;", "&"}
};

std::string ReadHTML(std::istream& stream)
{
    std::string html;
    std::string line;

    while (std::getline(stream, line))
    {
        html.append(line);
        html.append("\n");
    }

    return html;
}

std::pair<std::string, size_t> GetClosestHTMLEntity(const std::string& html, const size_t startPos)
{
    size_t minPos = html.find(HTML_ENTITY_MAP.begin()->first, startPos);

    const auto compareEntity = [&](const std::pair<std::string, std::string>& curr,
        const std::pair<std::string, std::string>& min) -> bool {
            size_t currPos = html.find(curr.first, startPos);
            if (minPos != std::string::npos && currPos >= minPos)
                return false;

            minPos = currPos;

            return true;
    };

    std::string closestEntity = std::min_element(HTML_ENTITY_MAP.begin(),
        HTML_ENTITY_MAP.end(),
        compareEntity)->first;

    if (minPos == std::string::npos)
    {
        return std::make_pair("", minPos);
    }

    return std::make_pair(closestEntity, minPos);
}

std::string DecodeHTML(const std::string& html)
{
    std::string decodedHTML;
    size_t lastPosInEncodedHTML = 0;

    std::string foundEntity;
    size_t foundPos = 0;

    while (lastPosInEncodedHTML < html.length())
    {
        std::pair<std::string, size_t> closestEntity = GetClosestHTMLEntity(html, lastPosInEncodedHTML);
        foundEntity = closestEntity.first;
        foundPos = closestEntity.second;

        if (foundPos == std::string::npos)
        {
            decodedHTML.append(html, lastPosInEncodedHTML, std::string::npos);

            break;
        }

        decodedHTML.append(html, lastPosInEncodedHTML, foundPos - lastPosInEncodedHTML);
        decodedHTML.append(HTML_ENTITY_MAP.at(foundEntity));

        lastPosInEncodedHTML = foundPos + foundEntity.length();
    }

    return decodedHTML;
}

void PrintHTML(const std::string& html, std::ostream& outStream)
{
    outStream << html << std::endl;
}