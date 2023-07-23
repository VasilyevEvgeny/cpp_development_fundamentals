#pragma once
#include "stops_database.h"
#include <vector>
#include <optional>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <cstdint>
#include "navigation_database.h"
#include <set>


struct RouteStats
{
	RouteStats()
	{
		stops_on_route = unique_stops = 0;
		route_length = 0;
	    direct_distance = curvature = 0;
	}

	int stops_on_route;
	int unique_stops;
	uint64_t route_length;
	double direct_distance;
	double curvature;
};


class IRouteInfo
{
public:
    IRouteInfo()
    {
		stops_.reserve(100);
		route_stats_ = RouteStats();
		stop_name_to_number_ = std::make_unique<std::unordered_map<std::string, std::vector<size_t>>>();
		stop_name_to_number_->reserve(100);
    }

	void AddStop(const std::string& stop);

	void Build(const std::shared_ptr<BusStopsDataBase>& stops_database, 
		const std::shared_ptr<NavigationDataBase>&, const std::string& route_name);

	virtual void RecomputeStatsInChildClass(const std::shared_ptr<BusStopsDataBase>&, 
		const std::shared_ptr<NavigationDataBase>&, const std::string&) = 0;

	[[nodiscard]] const RouteStats& GetRouteStats() const;

    virtual const std::vector<std::string>& GetStops() const = 0;

    virtual std::vector<std::string> GetEndStops() const = 0;

    [[nodiscard]] bool AreStopsNeighbors(const std::string& first, const std::string& second) const;

	virtual ~IRouteInfo() = default;

protected:
	RouteStats route_stats_;
	std::vector<std::string> stops_;
	std::unordered_set<std::string> unique_stops_;

	std::unique_ptr<std::unordered_map<std::string, std::vector<size_t>>> stop_name_to_number_;
};


class DirectRoute : public IRouteInfo
{
public:
	void RecomputeStatsInChildClass(const std::shared_ptr<BusStopsDataBase>&, 
		const std::shared_ptr<NavigationDataBase>&, const std::string&) override;

	const std::vector<std::string>& GetStops() const override;

    std::vector<std::string> GetEndStops() const override;

private:
    std::vector<std::string> all_stops_;
};


class RoundRoute : public IRouteInfo
{
public:
    void RecomputeStatsInChildClass(const std::shared_ptr<BusStopsDataBase>&, 
		const std::shared_ptr<NavigationDataBase>&, const std::string&) override;

    const std::vector<std::string>& GetStops() const override;

    std::vector<std::string> GetEndStops() const override;
};


class RoutesDataBase
{
public:
    RoutesDataBase()
    {
        routes_ = std::make_unique<std::unordered_map<std::string,
                std::shared_ptr<IRouteInfo>>>();
		routes_->reserve(2000);
    }

	void AddRoute(const std::string& bus_name, const std::shared_ptr<IRouteInfo>&);

	using RouteResponse = std::pair<std::string, 
    std::optional<RouteStats>>;

	void BuildAllRoutes(
		const std::shared_ptr<BusStopsDataBase>& stops_database, const std::shared_ptr<NavigationDataBase>&);

	[[nodiscard]] RouteResponse GetRouteStats(const std::string& bus) const;

    [[nodiscard]] const std::set<std::string>& GetRouteNames() const {
        return route_names_;
    }

    [[nodiscard]] const std::shared_ptr<IRouteInfo>& GetRouteInfo(const std::string& name) const {
        return routes_->at(name);
    }

    [[nodiscard]] const std::unique_ptr<std::unordered_map<std::string,
            std::shared_ptr<IRouteInfo>>>& GetRoutes() const {
        return routes_;
    }

private:
	std::unique_ptr<std::unordered_map<std::string,
            std::shared_ptr<IRouteInfo>>> routes_;

	std::set<std::string> route_names_;
};