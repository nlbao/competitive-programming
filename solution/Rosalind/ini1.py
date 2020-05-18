#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Bạn có thể comment bằng tiếng Việt có dấu thoải mái. Hãy dùng tín hiệu ở
# dòng trên để báo cho các Editor biết được đây là file utf8.

""" đây là cách thức được dùng để viết docstring cho một khối """

# Viết thêm cái này cho nó đẹp

"""
#-----------------------------------------------------------------------------
# Name:        Module Name
#
# Purpose:     
#
# Version:     1.1
#
# Author:      
#
# Created:     13/01/2009
# Updated:     30/04/2009
#
# Copyright:   (c) YourCompany
#
# Todo: 
#-----------------------------------------------------------------------------
"""

# Import các thư viện
from xml import sax
import re
import os

# Khai báo và triển khai các lớp

class YourClass:
    """ 
    Đặt các mô tả về lớp ở đây
    """
    
    def __init__(self):
        """ Viết một cái gì đó để giải thích nếu cần thiết """

        # KHÔNG nên viết quá 3 lệnh python trên một dòng, chương trình
        # của bạn sẽ rất khó hiểu.
        self.a, self.b = [], {}

        pass

# KHÔNG nên viết một dòng Python dài hơn 80 ký tự

def Test():
    pass

# Các lập trình viên python thường dùng cách này để test module

if __name__ == "__main__":
    Test()
   
if 1 > 0:
    print('Hello world')
    print (7 + 8)

str = "This is a rather long string containing\n\
several lines of text just as you would do in C.\n\
    Note that whitespace at the beginning of the line is\
 significant."
print(str)
