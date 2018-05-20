import time
import pandas as pd
import numpy as np

CITY_DATA = { 'Chicago': 'chicago.csv',
              'New York': 'new_york_city.csv',
              'Washington': 'washington.csv' }

def get_filters():
    """
    Asks user to specify a city, month, and day to analyze.

    Returns:
        (str) city - name of the city to analyze
        (str) month - name of the month to filter by, or "all" to apply no
                      month filter
        (str) day - name of the day of week to filter by, or "all" to apply
                    no day filter
    """
    print('Hello! Let\'s explore some US bikeshare data!')
    # get user input for city (chicago, new york city, washington).
    # HINT: Use a while loop to handle invalid inputs
    #city_list = ["Chicago", "New York", "Washington"]
    while True:
        sm = "Would you like to see data for {}, {}, or {}?"\
             .format(*CITY_DATA.keys())
        city = input(sm).title()
        if city in CITY_DATA.keys():
            break

    # get user input for month (all, january, february, ... , june)
    mon_list = ["January", "February", "March", "April", "May", "June"]
    sm = "Which month - {}, {}, {}, {}, {}, or {}?".format(*mon_list)
    month = input(sm).title()
    if month not in mon_list:
        month = "all"

    # get user input for day of week (all, monday, tuesday, ... sunday)
    days_list = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday",
                 "Saturday", "Sunday"]
    sm = "Which day - {}, {}, {}, {}, {}, {}, or {}?".format(*days_list)
    day = input(sm).title()
    if day not in days_list:
        day = "all"

    print('-'*40)
    return city, month, day


def load_data(city, month, day):
    """
    Loads data for the specified city and filters by month and day if
    applicable.

    Args:
        (str) city - name of the city to analyze
        (str) month - name of the month to filter by, or "all" to apply no
                      month filter
        (str) day - name of the day of week to filter by, or "all" to apply
                    no day filter
    Returns:
        df - Pandas DataFrame containing city data filtered by month and day
    """
    # load data file into a dataframe
    filename = CITY_DATA[city]
    print("xx - " + filename)
    df = pd.read_csv(filename)

    # convert the Start Time column to datetime
    df['Start Time'] = pd.to_datetime(df['Start Time'])

    # extract month and day of week from Start Time to create new columns
    df['month'] = df['Start Time'].dt.month
    df['day_of_week'] = df['Start Time'].dt.weekday_name

    # filter by month if applicable
    if month != 'all':
        # use the index of the months list to get the corresponding int
        months = ['january', 'february', 'march', 'april', 'may', 'june']
        month_num = months.index(month.lower()) + 1

        # filter by month to create the new dataframe
        df = df[df['month'] == month_num]

    # filter by day of week if applicable
    if day != 'all':
        # filter by day of week to create the new dataframe
        df = df[df['day_of_week'] == day.title()]

    return df


def time_stats(df):
    """Displays statistics on the most frequent times of travel."""

    print('\nCalculating The Most Frequent Times of Travel...\n')
    start_time = time.time()

    # display the most common month
    popular_month = df['month'].mode()[0]
    print('the most common month: ', popular_month)

    # display the most common day of week
    popular_day_of_week = df['day_of_week'].mode()[0]
    print('the most common day of week: ', popular_day_of_week)

    # display the most common start hour
    df['hour'] = df['Start Time'].dt.hour
    popular_hour = df['hour'].mode()[0]
    print('the most common start hour: ', popular_hour)

    print("\nThis took %s seconds." % (time.time() - start_time))
    print('-'*40)


def station_stats(df):
    """Displays statistics on the most popular stations and trip."""

    print('\nCalculating The Most Popular Stations and Trip...\n')
    start_time = time.time()

    # display most commonly used start station
    popular_start_station = df['Start Station'].mode()[0]
    print('most commonly used start station: ', popular_start_station)

    # display most commonly used end station
    popular_end_station = df['End Station'].mode()[0]
    print('most commonly used end station: ', popular_end_station)

    # display most frequent combination of start station and end station trip
    trip_series = df['Start Station'].astype(str) \
                  + " to " + df['End Station'].astype(str)

    popular_cmd_start_end = trip_series.mode()[0]

    print('most frequent combination of start station and end station trip: '
          , popular_cmd_start_end)

    print("\nThis took %s seconds." % (time.time() - start_time))
    print('-'*40)


def trip_duration_stats(df):
    """Displays statistics on the total and average trip duration."""

    print('\nCalculating Trip Duration...\n')
    start_time = time.time()

    # display total travel time


    # display mean travel time


    print("\nThis took %s seconds." % (time.time() - start_time))
    print('-'*40)


def user_stats(df):
    """Displays statistics on bikeshare users."""

    print('\nCalculating User Stats...\n')
    start_time = time.time()

    # Display counts of user types


    # Display counts of gender


    # Display earliest, most recent, and most common year of birth


    print("\nThis took %s seconds." % (time.time() - start_time))
    print('-'*40)


def main():
    while True:
        city, month, day = get_filters()
        print(city, month, day)
        df = load_data(city, month, day)

        time_stats(df)
        station_stats(df)
        #trip_duration_stats(df)
        #user_stats(df)

        restart = input('\nWould you like to restart? Enter yes or no.\n')
        if restart.lower() != 'yes':
            break


if __name__ == "__main__":
	main()
