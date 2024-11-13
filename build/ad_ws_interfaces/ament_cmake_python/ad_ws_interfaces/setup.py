from setuptools import find_packages
from setuptools import setup

setup(
    name='ad_ws_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('ad_ws_interfaces', 'ad_ws_interfaces.*')),
)
