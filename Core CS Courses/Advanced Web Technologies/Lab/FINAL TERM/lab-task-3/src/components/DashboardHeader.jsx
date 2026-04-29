import React from 'react'
import PropTypes from 'prop-types'
import { useTheme } from '../contexts/ThemeContext'
import { useStudents } from '../contexts/StudentContext'

function DashboardHeader({ title, tagline, extra, onNavigate }) {
  const { isDark, toggleTheme } = useTheme()
  const { favorites } = useStudents()

  return (
    <header className="dashboard-header">
      <div style={{ display: 'flex', flexDirection: 'column', alignItems: 'center' }}>
        <h1 className="dashboard-header__title">{title}</h1>
        <p className="dashboard-header__tagline">{tagline}</p>
        <div style={{ display: 'flex', gap: '16px', marginTop: '12px', alignItems: 'center' }}>
          <span style={{ fontSize: '0.9rem', color: 'rgba(255,255,255,0.85)' }}>
            ❤️ {favorites.size} favorite{favorites.size === 1 ? '' : 's'}
          </span>
          <button
            onClick={toggleTheme}
            aria-label={isDark ? 'Switch to light mode' : 'Switch to dark mode'}
            style={{
              background: 'rgba(255,255,255,0.2)',
              border: 'none',
              borderRadius: 'var(--radius-sm)',
              padding: '6px 12px',
              fontSize: '0.9rem',
              cursor: 'pointer',
              color: 'white',
              display: 'flex',
              alignItems: 'center',
              gap: '4px',
            }}
          >
            {isDark ? '☀️ Light' : '🌙 Dark'}
          </button>
        </div>
      </div>
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
  extra: PropTypes.node,
  onNavigate: PropTypes.func,
}
DashboardHeader.defaultProps = {
  extra: null,
  onNavigate: () => {},
}

export default DashboardHeader
