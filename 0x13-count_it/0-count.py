#!/usr/bin/python3
""" Count it """

import requests


def count_words(subreddit, word_list, hot_art=[], after=''):
    """ Function that queries the Reddit API, parses the title of all hot articles,
        and prints a sorted count of given keywords
    """
    try:
        req = requests.get('https://www.reddit.com/r/{}/hot.json?after={}'.
                         format(subreddit, after),
                         headers={'User-Agent': 'custom'},
                         allow_redirects=False)
        if after is None:
            dict = {}
            for word in word_list:
                for hot_word in hot_art:
                    if word == hot_word:
                        if word not in dict:
                            dict[word] = 1
                        else:
                            dict[word] += 1
            for word in sorted(dict, key=dict.get, reverse=True):
                if dict[word]:
                    print('{}: {}'.format(word, dict[word]))
            return hot_art
        for th in req.json().get('data').get('children'):
            hot_art += th.get('data').get('title').lower().split()
        after = req.json().get('data').get('after')
        count_words(subreddit, word_list, hot_art, after)
        return hot_art
    except:
        return None
