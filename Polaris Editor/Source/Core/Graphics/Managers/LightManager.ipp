template<typename T, unsigned int N>
bool LightManager::IsNameUsed(const std::array<std::pair<T, std::string>, N>& lights, const std::string& name)
{
	for (const auto& light : lights)
	{
		if (light.second == name) return true;
	}

	return false;
}