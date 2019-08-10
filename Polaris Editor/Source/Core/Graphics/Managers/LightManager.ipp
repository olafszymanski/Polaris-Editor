template<typename T, unsigned int N>
bool LightManager::IsNameUsed(const std::array<std::pair<T, std::string>, N>& lights, const std::string& name)
{
	for (unsigned int i = 0; i < N; ++i)
	{
		if (lights[i].second == name) return true;
	}

	return false;
}