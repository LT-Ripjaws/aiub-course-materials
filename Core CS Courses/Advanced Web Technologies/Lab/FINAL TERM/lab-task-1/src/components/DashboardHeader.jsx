import React from 'react'
import PropTypes from 'prop-types'

function DashboardHeader({ title, tagline, onNavigate }) {
  return (
    <header className="dashboard-header">
      <h1 className="dashboard-header__title">{title}</h1>
      <p className="dashboard-header__tagline">{tagline}</p>
      <nav className="dashboard-header__nav">
        <a href="#overview" className="dashboard-header__nav-item" onClick={onNavigate}>Overview</a>
        <a href="#students" className="dashboard-header__nav-item" onClick={onNavigate}>Students</a>
        <a href="#courses" className="dashboard-header__nav-item" onClick={onNavigate}>Courses</a>
      </nav>
    </header>
  )
}

DashboardHeader.propTypes = {
  title: PropTypes.string.isRequired,
  tagline: PropTypes.string.isRequired,
  onNavigate: PropTypes.func,
}
DashboardHeader.defaultProps = { onNavigate: () => {} }
export default DashboardHeader
